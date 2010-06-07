#ifndef UNICURR_H
#define UNICURR_H


#include "Common.h"

typedef Node DepList;

typedef struct unidadeCurricular_type{
	char *			unidadeCurricular;
	char *			acronimo;
	char *			DependenciasFortes;
	char *			DependenciasFracas;
	unsigned short	mec_number;
	byte			type;
	byte			semestre;
	short	totalsize;
} UniCurr;

UniCurr* UniCurr_new(char* unidadeCurricular,char* acronimo, char* depFortes,char* depFracas, unsigned short mec_number,byte type, byte semestre);
#define  UniCurr_emptyNew() UniCurr_new(NULL,NULL,NULL,NULL, 0,'0', '0');
UniCurr* UniCurr_new_fromString(char* line, char delimiter);
void UniCurr_init(	UniCurr* this, char* unidadeCurricular,	char* acronimo, char* depFortes, char* depFracas, unsigned short mec_number, byte type, byte semestre);
void UniCurr_toString(UniCurr* this);
void UniCurr_toString_debug(UniCurr* this);
void UniCurr_cleanup(UniCurr* this);
void UniCurr_destroy(UniCurr* this);

#endif
