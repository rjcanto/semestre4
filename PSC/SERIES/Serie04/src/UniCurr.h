#ifndef UNICURR_H
#define UNICURR_H
#include "DepList.h"

#include "Common.h"

typedef Node DepList;

typedef struct unidadeCurricular_type{
	char *			unidadeCurricular;
	char *			acronimo;
	DepList*		DependenciasFortes;
	DepList*		DependenciasFracas;
	unsigned short	mec_number;
	byte			type;
	byte			semestre;
} UniCurr;


UniCurr* UniCurr_new(char* unidadeCurricular, \
					char* acronimo, DepList* depFortes, \
					DepList* depFracas, unsigned short mec_number, \
					byte type, byte semestre);
					
void UniCurr_init(	UniCurr* this, char* unidadeCurricular, \
					char* acronimo, DepList* depFortes, \
					DepList* depFracas, unsigned short mec_number, \
					byte type, byte semestre);

void UniCurr_toString(UniCurr* this);
void UniCurr_cleanup(UniCurr* this);
void UniCurr_destroyer(UniCurr* this);

#endif
