#include "UniCurr.h"
/**
 * 	Conditional jump or move depends on uninitialised value(s)
 */ 
UniCurr* UniCurr_new(char* unidadeCurricular,char* acronimo, char* depFortes,char* depFracas, unsigned short mec_number,byte type, byte semestre)
{
	UniCurr* this = (UniCurr*)malloc(sizeof(UniCurr));
	UniCurr_init(this,unidadeCurricular, acronimo, depFortes, depFracas, mec_number, type, semestre);
	return this;						
}


static int UniCurr_equalize(char** field, byte* value, int* idx, int* size){
	if (value == NULL){
		*field=NULL;
		*idx+=1;
		*size+=1;
		free(value);
	}else{
		int tmpidx=strlen(value)+1;
		*field=value;
		*idx+=tmpidx;
		*size+=tmpidx;
	}
	return *idx;
}

static int UniCurr_equalize_byte(char* field, byte* value, int* idx, int* size){
	if (value == NULL){
		*field=0;
		*idx+=1;
	}else{
		int tmpidx=strlen(value)+1;
		*field=*value;
		*idx+=tmpidx;
		*size+=1;
	}
	free(value);

	return *idx;
}

UniCurr* UniCurr_new_fromString(char* line, char delimiter){
	UniCurr* this=(UniCurr*)malloc(sizeof(UniCurr));
	int size=0;
	int idx=0;
	char* value=line;
	
	/*Processa o Acronimo*/
	value=get_next_field(line+idx,delimiter);
	idx=UniCurr_equalize(&(this->acronimo),value, &idx, &size);

	/*Processa o Tipo, UniCurr_equalize_byte liberta o espaço alocado por
	 * get_next_field caso value seja NULL.
	 * */
	value=get_next_field(line+idx,delimiter);
	idx=UniCurr_equalize_byte(&(this->type),value,&idx, &size);
	
	/*Processa o Semestre, UniCurr_equalize_byte liberta o espaço alocado por
	 * get_next_field caso value seja NULL.
	 * */
	value=get_next_field(line+idx,delimiter);
	idx=UniCurr_equalize_byte(&(this->semestre),value,&idx, &size);
	
	/*Processa as DepFortes*/
	value=get_next_field(line+idx,delimiter);
	idx=UniCurr_equalize(&(this->DependenciasFortes),value, &idx, &size);

	/*Processa as DepFracas*/
	value=get_next_field(line+idx,delimiter);
	idx=UniCurr_equalize(&(this->DependenciasFracas),value, &idx, &size);

	/*Processa o Nome da Cadeira*/
	value=get_next_field(line+idx,delimiter);
	idx=UniCurr_equalize(&(this->unidadeCurricular),value, &idx, &size);

	/*Processa o numero de Docente*/
	value=get_next_field(line+idx,delimiter);
	
	
	if (value == NULL){
		this->mec_number=0;
	}else{
		if ( sscanf(value, "%hu", &(this->mec_number)) == 0 )
		{
			puts("Not a Number");
			this->mec_number =0;
		}
	}
	size+=sizeof(this->mec_number);
	this->totalsize=size;
	free(value);
	
	return this;
}

static void UniCurr_initiate(char** field, char* value, int* size){
	if (value != NULL){
		char* fp;
		int tmpidx=strlen(value)+1;
		*size+=tmpidx;

		fp=(char*)malloc(tmpidx);
		strcpy(fp,value);
		*field=fp;		
	}else{ *field = NULL;*size+=1;}
}

					
void UniCurr_init(	UniCurr* this, char* unidadeCurricular,	char* acronimo, char* depFortes, char* depFracas, unsigned short mec_number, byte type, byte semestre){
	int size=0;
	
	/*Processa Unidade Curricular*/
	UniCurr_initiate(&(this->unidadeCurricular),unidadeCurricular, &size);
	/*Processa Acronimo*/
	UniCurr_initiate(&(this->acronimo),unidadeCurricular, &size);
	/*Processa Dependencias Fortes*/
	UniCurr_initiate(&(this->DependenciasFortes),unidadeCurricular, &size);
	/*Processa Dependencias Fracas*/
	UniCurr_initiate(&(this->DependenciasFracas),unidadeCurricular, &size);
	
	UniCurr_initiate(&(this->unidadeCurricular),unidadeCurricular, &size);

	this->mec_number=mec_number;
	size+=sizeof(this->mec_number);
	
	this->type =type;
	size+=sizeof(this->type);
	
	this->semestre =semestre;					
	size+=sizeof(this->semestre);
	
	this->totalsize=size;
}


void UniCurr_toString(UniCurr* this){
	printf("Acronimo: %s\tNome: %s\n",this->acronimo,this->unidadeCurricular);
	printf("\tDependencias Fortes: %s\n\tDependencias Fracas: %s\n",this->DependenciasFortes,this->DependenciasFracas);
	printf("\tTipo: %c\tSemestre: %d\n",this->type,this->semestre);
	printf("\tDocente Responsável: %hu\n",this->mec_number);
}

void UniCurr_toString_debug(UniCurr* this){
	printf("Acronimo: %s (%u)\tNome: %s (%u)\n",this->acronimo,strlen(this->acronimo)+1,this->unidadeCurricular,strlen(this->unidadeCurricular)+1);
	printf("\tDependencias Fortes: %s (%u)\n\tDependencias Fracas: %s (%u)\n",this->DependenciasFortes,(this->DependenciasFortes!= NULL)?strlen(this->DependenciasFortes)+1:0,this->DependenciasFracas,(this->DependenciasFracas!= NULL)?strlen(this->DependenciasFracas)+1:0);
	printf("\tTipo: %c (%u)\tSemestre: %d(%u)\n",this->type,sizeof(this->type),this->semestre,sizeof(this->semestre));
	printf("\tDocente Responsável: %hu (%u)\n",this->mec_number,sizeof(this->mec_number));
	printf("\ttotal size: %hu byes\n",this->totalsize);
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

void UniCurr_destroy(UniCurr* this){
	if (this == NULL) return;
	UniCurr_cleanup(this);
	free(this);	
}


