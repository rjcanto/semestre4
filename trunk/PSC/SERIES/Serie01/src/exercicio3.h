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


void simplyPrint(InfoUC *uniCurr);
void listAllUCFilter(char type);
void listAllUC();
void listFromSemester(char semestre);
unsigned int isDep(char* uniCurr,InfoUC *dependencias[]);
void listDepUC(char* uniCurr);
void trim(char* token);
InfoUC* findUC(char* uc);
void parseDependencias(char* uc, struct info_uc *dependencias[],char delimiter);
void populateDB(char * line,int idx);
void printSyntax();

#endif
