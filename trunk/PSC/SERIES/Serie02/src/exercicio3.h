/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/
#ifndef _SERIE01_EX03
#define _SERIE01_EX03

#include "serie01.h"

#define MAX_UC 50
#define MAX_LINE_SIZE 100
#define MAX_FIELDS 5

#define MAXDEPCURR 3

#define OBRIGATORIO 'B'
#define OPTATIVO 'P'
#define COMPLEMENTAR 'C'
#define ALL_HEADER "Listagem de Todas as Unidades Curriculares"
#define FILTER_HEADER "Listagem de Unidades Curriculares Filtradas"
#define SEMESTRE_HEADER "Listagem de Unidades de um dado semestre"
#define DEP_HEADER "Listagem de Unidade Curriculares Dependentes"

/*
 * Lista todas as Unidades Curriculares
 */
#define listAllUC()  list(ALL_HEADER,cmpAll,NULL)

/*
 * Lista as Unidades Curriculares mediante um filtro:
 * B - Obrigatorio
 * P - Optativa
 * C - Complementar
 */
#define listAllUCFilter(type)  {char c=type;list(FILTER_HEADER,cmpAllFilter,&c);}

/*
 * Lista todas as Unidades Curriculares de um dado Semestre
 */
#define listFromSemester(semestre) {int mask=1<<(semestre-1);list(SEMESTRE_HEADER,cmpAllSemester,&mask);}

/*
 * Lista todas as Unidades Curriculares que têm dependencias de uma dada
 * cadeira
 */
#define listDepUC(uniCurr) list(DEP_HEADER,cmpAllDep,&uniCurr)

typedef struct info_uc {
   char uc[6];        		/* Abreviatura da unidade curricular: POO, ALGA, ... */
   char tipo;         		/* Tipo: B-obrigatória, P-opcional, C-complementar */
   unsigned char sem; 		/* Bitmap dos semestres em que funciona */
   struct info_uc *depF[MAXDEPCURR]; /* Dependências fortes: NULL se não existe */
   struct info_uc *depf[MAXDEPCURR]; /* Dependências fracas: NULL se não existe */
} InfoUC;


void printHeader(char *header);
void printTrailer(int nbrRecords);
void simplyPrint(InfoUC *uniCurr);

void list(char* header,int (*condition)(const void*,const void*),void *p);
int cmpAll(const void* uc,const void* p);
int cmpAllFilter(const void* uc,const void* p);
int cmpAllSemester(const void* uc,const void* p);
int cmpAllDep(const void* uc,const void* p);


#define listAllUCObligatory() {char c=OBRIGATORIO;list(FILTER_HEADER,cmpAllFilter,&c);}
#define listAllUCOptative() {char c=OPTATIVO;list(FILTER_HEADER,cmpAllFilter,&c);}
#define listAllUCComple() {char c=COMPLEMENTAR;list(FILTER_HEADER,cmpAllFilter,&c);}

unsigned int isDep(char* uniCurr,InfoUC *dependencias[]);
void trim(char* token);

InfoUC* findUC(char* uc);
void parseDependencias(char* uc, struct info_uc *dependencias[],char delimiter);
void populateDB(char * line,int idx);
void printSyntax(char * program);



#endif
