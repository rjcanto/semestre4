#include "UniCurr.h"

UniCurr* UniCurr_new(char* unidadeCurricular,char* acronimo, Dep_list* depFortes, \
					DepList* depFracas, unsigned short mec_number,	byte type, byte semestre){
	UniCurr* this = (UniCurr*)malloc(sizeof(UniCurr));
	UniCurr_init(this,unidadeCurricular, acronimo, depFortes, depFracas, mec_number, type, semestre);
	return this;						
}
					
void UniCurr_init(	UniCurr* this, char* unidadeCurricular, \
					char* acronimo, DepList* depFortes, \
					DepList* depFracas, unsigned short mec_number, \
					byte type, byte semestre);

void UniCurr_toString(UniCurr* this);

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
	if (this->depFortes != NULL){
		DepList_deleteNode(this->depFortes);
		this->depFortes = NULL;
	}
	if (this->depFracas != NULL){
		DepList_deleteNode(this->depFracas);
		this->depFracas = NULL;
	}	
}

void UniCurr_destroyer(UniCurr* this){
	if (this == NULL) return;
	UniCurr_cleanup(this);
	free(this);	
}
