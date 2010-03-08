/*
 Escreva um programa que leia, via standard input, a informação sobre as unidades curriculares de um curso,
disponível no ficheiro de texto anexo a este enunciado. Considere que não existem mais do que 50 unidades
curriculares. O programa deverá, apresentar no standard output uma listagem das unidades curriculares
filtrada com um dos seguintes critérios (e outros à sua escolha), de acordo com uma opção indicada na linha
de comando:
    As unidades curriculares de um determinado semestre;
    As unidades curriculares obrigatórias;
    As unidades curriculares que dependem de uma determinada unidade curricular.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_UC 50
#define MAX_LINE_SIZE 100
#define MAX_FIELDS 5
#define OBRIGATORIO 'B'
#define OPTATIVO 'P'
#define COMPLEMENTAR 'C'
#define MAXDEPCURR 3
#define listAllUCObligatory() listAllUCFilter(OBRIGATORIO)
#define listAllUCOptative() listAllUCFilter(OPTATIVO)
#define listAllUCComple() listAllUCFilter(COMPLEMENTAR)




typedef struct info_uc {
   char uc[6];        		/* Abreviatura da unidade curricular: POO, ALGA, ... */
   char tipo;         		/* Tipo: B-obrigatória, P-opcional, C-complementar */
   unsigned char sem; 		/* Bitmap dos semestres em que funciona */
   struct info_uc *depF[MAXDEPCURR]; /* Dependências fortes: NULL se não existe */
   struct info_uc *depf[MAXDEPCURR]; /* Dependências fracas: NULL se não existe */
} InfoUC;

InfoUC ucDb[MAX_UC];
unsigned int size=0;


void simplyPrint(InfoUC *uniCurr){
	printf("%-8s|%-4c|%-8d|%-5s  %-5s  %-5s|%-5s %-5s %-5s\n",\
	uniCurr->uc,uniCurr->tipo,uniCurr->sem,\
	(uniCurr->depF[0]->uc != NULL)?uniCurr->depF[0]->uc:"",\
	(uniCurr->depF[1]->uc != NULL)?uniCurr->depF[1]->uc:"",\
	(uniCurr->depF[2]->uc != NULL)?uniCurr->depF[2]->uc:"",\
	(uniCurr->depf[0]->uc != NULL)?uniCurr->depf[0]->uc:"",\
	(uniCurr->depf[1]->uc != NULL)?uniCurr->depf[1]->uc:"",\
	(uniCurr->depf[2]->uc != NULL)?uniCurr->depf[2]->uc:"");
}

void listAllUCFilter(char type){
		int i;
		puts("Uni.Curr|Tipo|Semestre|Dependencias Fortes|Dependencias Fracas");
		for (i=0;i<size;++i)
			if (ucDb[i].tipo == type)
				simplyPrint(&ucDb[i]);
}
void listAllUC(){
		int i;
		puts("Uni.Curr|Tipo|Semestre|Dependencias Fortes|Dependencias Fracas");
		for (i=0;i<size;++i)
				simplyPrint(&ucDb[i]);
}
void listFromSemester(char semestre){
	int mask=1;
	int i=0;
	mask=mask<<(semestre-1);
	puts("Uni.Curr|Tipo|Semestre|Dependencias Fortes|Dependencias Fracas");
	for (i=0;i<size;++i)
		if (ucDb[i].sem & mask)
			simplyPrint(&ucDb[i]);
}



unsigned int isDep(char* uniCurr,InfoUC *dependencias[]){
	int i;
	for(i=0;i<MAXDEPCURR;++i){
		if(dependencias[i] == NULL)
			return 0;
		if (strcmp(dependencias[i]->uc,uniCurr) == 0)
			return 1;
	 }
	return 0;
}

void listDepUC(char* uniCurr){
	
	int i;
	puts("Uni.Curr|Tipo|Semestre|Dependencias Fortes|Dependencias Fracas");
	for (i=0;i<size;++i){
		if(isDep(uniCurr,ucDb[i].depF))
			simplyPrint(&ucDb[i]);
		if(isDep(uniCurr,ucDb[i].depf))
			simplyPrint(&ucDb[i]);
	}
}


void trim(char* token){
	unsigned int len=strlen(token);
	char* lTok=token;
	char* rTok=token+len;
	unsigned char stop=0;
	
	while ( lTok <= rTok && stop !=3 ){
		if (*lTok == ' ' && stop != 1) ++lTok; else stop+=1;			
		
		
		if (stop!=2 && ( *rTok == ' ' || *rTok == '\r' || *rTok == '\n' ||  *rTok == '\0' || *rTok == 10 || *rTok == EOF)){
			*rTok=0;
			--rTok;
		} else {
			stop+=2;			
		}
	}
	if((rTok-lTok)>=0) strncpy(token,lTok,rTok-lTok);
}

InfoUC* findUC(char* uc){
	int i;
	for(i=0;i<size;++i){
		if (strcmp(ucDb[i].uc,uc) == 0)
			return &ucDb[i];
	}
	return NULL;
}

void parseDependencias(char* uc, struct info_uc *dependencias[],char delimiter){
	int i=0;
	char* ptr=uc;
	while(*ptr){
		if(*ptr == delimiter){
			*ptr=0;
			dependencias[i++]=findUC(uc);
			uc=ptr+1;
		}
	++ptr;
	}
	dependencias[i++]=findUC(uc);
}

void populateDB(char * line,int idx){
	char delim='|';
	char subDelim=';';
	int nbrfields=0;
	char * lineptr=line;
	while(*lineptr != '\r' && *lineptr != '\n' && *lineptr != '\0'&&*lineptr != 10&& *lineptr != EOF){
		if (*lineptr == delim){
			*lineptr=0;			
			switch(	nbrfields ){
					case 0:
						strcpy(ucDb[idx].uc,line);
						break;
					case 1:
						ucDb[idx].tipo=*line;
						break;
					case 2:
						ucDb[idx].sem=(char)atoi(line);
						break;
					case 3:
						if (lineptr - line != 0)
							parseDependencias(line, ucDb[idx].depF,subDelim);
						break;
			}
			line=lineptr+1;
			++nbrfields;
		}
		++lineptr;
	}
	*lineptr=0;
	if (lineptr - line != 0)
		parseDependencias(line, ucDb[idx].depf,subDelim);
}

void printSyntax(){
	 puts("Escreva um programa que leia, via standard input, a informação sobre as unidades curriculares de um curso, \
	 disponível no ficheiro de texto anexo a este enunciado. Considere que não existem mais do que 50 unidades\
	 curriculares. O programa deverá, apresentar no standard output uma listagem das unidades curriculares\
	 filtrada com um dos seguintes critérios (e outros à sua escolha), de acordo com uma opção indicada na linha\
	 de comando:");
	puts("Somente uma das seguintes Opções");
	puts("-a: All");
	puts("-b: Obrigatorias");
	puts("-c: Complementares");
	puts("-d <UnCurr>: Unidades Curriculares com dependencia de <UnCurr>");
	puts("-o: Optativas");
	puts("-s <sem>: Unidade Curriculares que funcinam no semestre <sem>");
	
}

int main(int argc,char** argv){

	char line[MAX_LINE_SIZE];
	while((fgets(line,MAX_LINE_SIZE,stdin))!= NULL){
		populateDB(line,size);
		++size;
	}
	
	
	if (argc == 1){
		printSyntax();
		return 1;
	}
	
	if (strcmp(argv[1],"-a") == 0)
		listAllUC();
	else if (strcmp(argv[1],"-b")== 0)
		listAllUCObligatory();
	else if (strcmp(argv[1],"-c")== 0)
		listAllUCComple();
	else if (strcmp(argv[1],"-d")== 0){
		if (argc == 3)
			listDepUC(argv[2]);
	}else if (strcmp(argv[1],"-o")== 0)
		listAllUCOptative();
	else if (strcmp(argv[1],"-s")== 0){
		if (argc == 3)
			listFromSemester(atoi(argv[2]));
	}else
		printSyntax();
	return 1;
}
