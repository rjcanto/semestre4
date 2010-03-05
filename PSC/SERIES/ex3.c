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
#include <string.h>
#define MAX_UC 50
#define MAX_LINE_SIZE 100
#define MAX_FIELDS 5


typedef struct info_uc {
   char uc[5];        		/* Abreviatura da unidade curricular: POO, ALGA, ... */
   char tipo;         		/* Tipo: B-obrigatória, P-opcional, C-complementar */
   unsigned char sem; 		/* Bitmap dos semestres em que funciona */
   struct info_uc *depF[3]; /* Dependências fortes: NULL se não existe */
   struct info_uc *depf[3]; /* Dependências fracas: NULL se não existe */
} InfoUC;

InfoUC* ucDb[MAX_UC];
unsigned int size=0;

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
void populateDB1(char * line,int idx){
	char* token=NULL;
	char delim='|';
	int nbrfields=0;
	char* arr[MAX_FIELDS];
	token = strtok(line, &delim);

	while(token != NULL){
		trim(token);
		arr[nbrfields++]=token;
		printf("[  %s ]", token);
		token = strtok(NULL, &delim);
	}
	printf("\n");
}

void populateDB(char * line,int id){
	char* ptr=line;
	char uc[5];
	unsigned char sem;
	int idx=0;
	while(*ptr!='|'){
		*(uc+idx)=*ptr;
		++ptr;
		++idx;
	}
	idx=0;
	strcpy(ucDb[id]->uc,uc);
	ucDb[id]->tipo=*(ptr++);
	++ptr;
	while(*ptr!='|'){
		*(sem+idx)=*ptr;
		++ptr;
		++idx;
	}
	idx=0;
	strcpy(ucDb[id]->sem,sem);
}

InfoUC* findUC(char[] uc){
	return NULL;
}


int main(int argcm,char** argv){

	char line[MAX_LINE_SIZE];
	int idx=0; 
	while((fgets(line,MAX_LINE_SIZE,stdin))!= NULL){
		populateDB(line,idx);
		++idx;
	}
	

	return 0;
}
