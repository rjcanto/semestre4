	/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/
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

#include "exercicio3.h"

InfoUC ucDb[MAX_UC];
unsigned int size=0;
void * ssearch (const void * key, const void * base, size_t size,size_t elem_size, int (* compare)(const void * k, const void * p)
);

void printHeader(char *header){
		puts("================================================================================");
		puts(header);
		puts("================================================================================");
		puts("Uni.Curr|Tipo|Semestre|Dependencias Fortes|Dependencias Fracas");	
}
void printTrailer(int nbrRecords){
		char c=(nbrRecords>1)?'s':' ';
		puts("================================================================================");
		printf("Numero de registo%c encontrado%c: %d\n",c,c,nbrRecords);
		puts("================================================================================");
}

/*
 * Imprime no ecrâ o conteudo da estrutura.
 * */
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


/*
 * Imprime no ecrâ o relatorio.
 * */
void list(char* header,int (*compare)(const void *,const void*),void *key){
		struct info_uc *uniCurr=NULL;
		struct info_uc * base=&ucDb[0];
		int nbr=0;
		int i=0;
		int s=size;
		printHeader(header);
		/*
		void * ssearch (
		+8		const void * key, 
		+12		const void * base, 
		+16		size_t size,
		+20		size_t elem_size, 
		+24		int (* compare)(const void * k, const void * p)
		);
		 
		 ssearch(key, ucDb[i], size,sizeof(ucDb[0]) , condition);
		 * */
		
		/*for (i=0;i<size;(++i)){
			if (condition(&ucDb[i],key)){
				simplyPrint(&ucDb[i]);
				++nbr;
			}
		}*/
		
		
		if (ssearch(key, base, s ,sizeof(struct info_uc),compare))
			simplyPrint(uniCurr);
/*		while(){
				
				simplyPrint(uniCurr);
				
				++nbr;
				base=uniCurr;
				
				s=s-(base-ucDb);
		}
		
	*/	
		printTrailer(nbr);
}

/*
 * Comparadores
 * */
int cmpAll(const void* uc,const void* p){
	return 1;
}
int cmpAllFilter(const void* uc,const void* p){
	return ((*(struct info_uc*)uc).tipo == *(char*)p);
}
int cmpAllSemester(const void* uc,const void* p){
	return (*(char*)p & (*(struct info_uc*)uc).sem );
}
int cmpAllDep(const void* uc,const void* p){
	return (isDep(*(char**)p,(*(struct info_uc*)uc).depF) || isDep(*(char**)p,(*(struct info_uc*)uc).depf));
}


/*
 * Verifica se uma dada Unidade Curricular tem dependencias de outra 
 * unidade curricular.
 * */
unsigned int isDep(char* uniCurr,InfoUC *dependencias[]){
	int i;
	for(i=0;i<MAXDEPCURR;++i){
		if(dependencias[i] == NULL){
			return 0;
		}
		if (strcmp(dependencias[i]->uc,uniCurr) == 0){
			return 1;
		}
	 }
	return 0;
}

/*
 * Faz trim da string
 * */
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

/*
 * Pesquisa a Unidade Curricular na "Base de Dados"
 * */
InfoUC* findUC(char* uc){
	int i;
	for(i=0;i<size;++i){
		if (strcmp(ucDb[i].uc,uc) == 0)
			return &ucDb[i];
	}
	return NULL;
}
/*
 * Processa as dependências de uma Unidade Curricular
 * */
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
/*
 * Processa cada linha recebida para "alimentar" a "base de dados"
 * */
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
/*
 * Demonstra o objectivo do programa e a respectiva syntaxe.
 * */
void printSyntax(char * program){
	 puts("Escreva um programa que leia, via standard input, a informação sobre as unidades curriculares de um curso, \
	 disponível no ficheiro de texto anexo a este enunciado. Considere que não existem mais do que 50 unidades\
	 curriculares. O programa deverá, apresentar no standard output uma listagem das unidades curriculares\
	 filtrada com um dos seguintes critérios (e outros à sua escolha), de acordo com uma opção indicada na linha\
	 de comando:");
	printf("%s opção",program);
	puts("Somente uma das seguintes Opções");
	puts("-a: All");
	puts("-b: Obrigatorias");
	puts("-c: Complementares");
	puts("-d <UnCurr>: Unidades Curriculares com dependencia de <UnCurr>");
	puts("-p: Optativas");
	puts("-s <sem>: Unidade Curriculares que funcinam no semestre <sem>");
	
}

int main(int argc,char** argv){
	char line[MAX_LINE_SIZE];
	/*
	 * Valida se existem argumentos
	 * */
	if (argc == 1){
		printSyntax(argv[0]);
		return 1;
	}

	/*
	 * Popula a base de dados
	 * */
	while((fgets(line,MAX_LINE_SIZE,stdin))!= NULL){
		populateDB(line,size);
		++size;
	}
	
	
	/*
	 * Executa a função para o respectivo argumento
	 * */
	
	if (strcmp(argv[1],"-a") == 0){
		listAllUC();
	}else if (strcmp(argv[1],"-b")== 0){
		listAllUCObligatory();
	}else if (strcmp(argv[1],"-c")== 0){
		listAllUCComple();
	}else if (strcmp(argv[1],"-d")== 0){
		if (argc == 3)
			listDepUC(argv[2]);
	}else if (strcmp(argv[1],"-p")== 0){
		listAllUCOptative();
	}else if (strcmp(argv[1],"-s")== 0){
		if (argc == 3){
			listFromSemester(atoi(argv[2]));
		}
	}else{
		printSyntax(argv[0]);
	}
	return 1;
}
