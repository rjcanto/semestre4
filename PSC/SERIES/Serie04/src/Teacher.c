#include "Teacher.h"

Teacher* Teacher_new(char * name, char * email, unsigned short mec_number){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	Teacher_init(this, name,email,mec_number);
	return this;	
}

static void Teacher_initiate(char** field, char* value, int* size){
	if (value != NULL){
		char* fp;
		int tmpidx=strlen(value)+1;
		*size+=tmpidx;

		fp=(char*)malloc(tmpidx);
		strcpy(fp,value);
		*field=fp;		
	}else{ *field = NULL;*size+=1;}
}

static int Teacher_equalize(char** field, byte* value, int* idx, int* size){
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


Teacher* Teacher_new_fromString(const char* line, char delimiter){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	int size=0;
	int idx=0;
	char * value=0;
	
	/*Processa o numero de Docente*/
	value=get_next_field(line+idx,delimiter);
		
	if (value == NULL){
		this->mec_number=0;
		idx+=1;
	}else{
		idx+=strlen(value)+1;
		if (sscanf(value,"%hu",&(this->mec_number)) == 0 )
		{
			puts("Not a Number");
			this->mec_number =0;
			idx+=1;
		}
	}
	size+=sizeof(this->mec_number);
	free(value);value=NULL;
	
	/*Processa o Nome do Docente*/
	value=get_next_field(line+idx,delimiter);
	idx=Teacher_equalize(&(this->name),value, &idx, &size);	
	
	/*Processa o Email*/
	value=get_next_field(line+idx,delimiter);
	idx=Teacher_equalize(&(this->email),value, &idx, &size);	

	this->totalsize=size;
	return this;	
}


void Teacher_init(Teacher* this, char * name, char * email, unsigned short mec_number){
	int size=0;
	Teacher_initiate(&(this->name),name, &size);
	Teacher_initiate(&(this->email),email, &size);
	this->mec_number = mec_number;
	size+=sizeof(this->mec_number);
	this->totalsize=size;
}

void Teacher_toString(Teacher* this){
	
	printf ("Number: %5hu\tName: %-60.60s\tEmail: %-60.60s\n",this->mec_number,(this->name==NULL)?"NULL":this->name,(this->email==NULL)?"NULL":this->email);
}

void Teacher_toString_debug(Teacher* this){
	printf ("Number: %5hu (%u)\tName: %-60.60s (%u)\tEmail: %-60.60s(%u)\nTotal Size: %hu\n",this->mec_number,sizeof(this->mec_number),\
	(this->name==NULL)?"NULL":this->name,(this->name==NULL)?0:strlen(this->name)+1,\
	(this->email==NULL)?"NULL":this->email,(this->email==NULL)?0:strlen(this->email)+1,\
	this->totalsize);
}

void Teacher_cleanup(Teacher* this){
	if (this == NULL) return;
	
	if(this->name != NULL ){
		free(this->name);	this->name = NULL;
	}
	if(this->email != NULL){
		free(this->email);	this->email = NULL;
	}
}
void Teacher_destroy(Teacher * this){
	if (this == NULL) return;
	Teacher_cleanup(this);
	free(this);
}

