#include "UniCurr.h"


/**
 * 	Conditional jump or move depends on uninitialised value(s)
 */ 
UniCurr* UniCurr_new(char* unidadeCurricular,char* acronimo, char* depFortes,char* depFracas, unsigned short mec_number,	byte type, byte semestre)
{
	UniCurr* this = (UniCurr*)malloc(sizeof(UniCurr));
	UniCurr_init(this,unidadeCurricular, acronimo, depFortes, depFracas, mec_number, type, semestre);
	return this;						
}

int UniCurr_assign_Value(char * key, char* value){
	if (value == NULL){
		key=NULL;

		puts("NULL>>");
		return 1;
	}else{
		key = value;
		puts(value);
		return strlen(value)+1;
	}	
}

UniCurr* UniCurr_new_fromString(char* line, char delimiter){
	UniCurr* this=(UniCurr*)malloc(sizeof(UniCurr));
	
	int idx=0;
	char* tmp=line;
	/*Processa o Acronimo*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->acronimo=NULL;
		idx+=1;
		free(tmp);
	}else{
		this->acronimo=tmp;
		idx+=strlen(tmp)+1;
	}
	
	/*Processa o Tipo*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->type=0;
		idx+=1;
	}else{
		this->type=*tmp;
		idx+=strlen(tmp)+1;
	}
	free(tmp);
	/*Processa o Semestre*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->semestre=0;
		idx+=1;
	}else{
		this->semestre=*tmp;
		idx+=strlen(tmp)+1;
	}
	free(tmp);
	/*Processa as DepFortes*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->DependenciasFortes=NULL;
		idx+=1;
		free(tmp);		
	}else{
		this->DependenciasFortes=tmp;
		idx+=strlen(tmp)+1;
	}

	/*Processa as DepFracas*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->DependenciasFracas=NULL;
		idx+=1;
		free(tmp);		
	}else{
		this->DependenciasFracas=tmp;
		idx+=strlen(tmp)+1;
	}

	/*Processa o Nome da Cadeira*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->unidadeCurricular=NULL;
		idx+=1;
		free(tmp);		
	}else{
		this->unidadeCurricular=tmp;
		idx+=strlen(tmp)+1;
	}

	/*Processa o numero de Docente*/
	tmp=get_next_field(line+idx,delimiter);
	
	
	if (tmp == NULL){
		this->mec_number=0;
	}else{
		if ( sscanf(tmp, "%hu", &(this->mec_number)) == 0 )
		{
			puts("Not a Number");
			this->mec_number =0;
		}
	}
	free(tmp);
	return this;
}

					
void UniCurr_init(	UniCurr* this, char* unidadeCurricular,	char* acronimo, char* depFortes, char* depFracas, unsigned short mec_number, byte type, byte semestre){
	
	if (unidadeCurricular != NULL){
		char* uc=(char*)malloc(strlen(unidadeCurricular)+1);
		strcpy(uc,unidadeCurricular);
		this->unidadeCurricular=uc;		
	}else{ this->unidadeCurricular = NULL;}
	
	if (acronimo != NULL){
		char* ac=(char*)malloc(strlen(acronimo)+1);
		strcpy(ac,acronimo);
		this->acronimo=ac;
	}else{this->acronimo = NULL;}
	
	if (depFortes != NULL){
		char* dF=(char*)malloc(strlen(depFortes)+1);
		strcpy(dF,depFortes);
		this->DependenciasFortes = dF;		
	}else{ depFortes = NULL;}
	
	if (depFracas != NULL){
		char* df=(char*)malloc(strlen(depFracas)+1);
		strcpy(df,depFracas);
		this->DependenciasFracas = df;			
	}else{this->DependenciasFracas = NULL;}
	
	this->mec_number=mec_number;
	this->type =type;
	this->semestre =semestre;					
}

void UniCurr_toString(UniCurr* this){
	puts("Method yet to be implemented");
	printf("Acronimo: %s\tNome: %s\n",this->acronimo,this->unidadeCurricular);
	printf("\tDependencias Fortes: %s\n\tDependencias Fracas: %s\n",this->DependenciasFortes,this->DependenciasFracas);
	printf("\tTipo: %c\tSemestre: %d\n",this->type,this->semestre);
	printf("\tDocente Responsável: %hu\n",this->mec_number);
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
		free(this->DependenciasFortes);
		this->DependenciasFortes=NULL;
	}
	if (this->DependenciasFracas != NULL){
		free(this->DependenciasFracas);
		this->DependenciasFracas=NULL;
	}	
}

void UniCurr_destroyer(UniCurr* this){
	if (this == NULL) return;
	UniCurr_cleanup(this);
	free(this);	
}


int main()
{
	 UniCurr * t2 = t2;
	 /*UniCurr * t2 = t2;*/
	 char string[]="ALGA|B|1|||Álgebra Linear e Geometria Analítica|617\0";
	 
	 
	/*t1 = UniCurr_new("EICARAMBA","EIC","XPTO;ABRA",NULL,123,'B',1);*/
	t2 = UniCurr_new_fromString(string,'|');
	
	/*UniCurr_toString(t1);*/
	UniCurr_toString(t2);
	
	/*UniCurr_destroyer(t1);*/
	UniCurr_destroyer(t2);

return 0;	
}
