#include "UniCurr.h"

UniCurr* UniCurr_new(char* unidadeCurricular,char* acronimo, DepList* depFortes,\
					DepList* depFracas, unsigned short mec_number,	byte type, byte semestre){
	UniCurr* this = (UniCurr*)malloc(sizeof(UniCurr));
	UniCurr_init(this,unidadeCurricular, acronimo, depFortes, depFracas, mec_number, type, semestre);
	return this;						
}
					
void UniCurr_init(	UniCurr* this, char* unidadeCurricular, \
					char* acronimo, DepList* depFortes, \
					DepList* depFracas, unsigned short mec_number, \
					byte type, byte semestre){
	if (unidadeCurricular != NULL){
		
	}else{
		unidadeCurricular = NULL;
	}
	if (acronimo != NULL){
		
	}else{
		acronimo = NULL;
	}
	if (depFortes != NULL){
		
	}else{
		depFortes = NULL;
	}
	if (depFracas != NULL){
		
		
	}else{
		depFracas = NULL;
	}
	this->mec_number=mec_number;
	this->type =type;
	this->semestre =semestre;					
}

void UniCurr_toString(UniCurr* this){
	/*Method yet to be implemented*/
}

void UniCurr_cleanup(UniCurr* this){
	if (this == NULL) return;
	if (this->unidadeCurricular != NULL){
		free(this->unidadeCurricular);
		this->unidadeCurricular=NULL;
	}
	if (this->acronimo != NULL){
		free(this->acronimo);
		this->acronimo=NULL;
	}
	if (this->DependenciasFortes != NULL){
		DepList_cleanup(this->DependenciasFortes);
	}
	if (this->DependenciasFracas != NULL){
		DepList_cleanup(this->DependenciasFracas);
	}	
}

void UniCurr_destroyer(UniCurr* this){
	if (this == NULL) return;
	UniCurr_cleanup(this);
	free(this);	
}
