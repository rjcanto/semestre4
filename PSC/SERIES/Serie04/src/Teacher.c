#include "Teacher.h"



Teacher* Teacher_new(char * name, char * email, unsigned short mec_number){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	Teacher_init(this, name,email,mec_number);
	return this;	
}
void Teacher_init(Teacher* this, char * name, char * email, unsigned short mec_number){
	if (name != NULL){
		char *n=(char*)malloc(strlen(name));
		strcpy(n,name);
		this->name=n;
	}else{
		this->name=NULL;
	}
	if (email != NULL){
		char* n =(char*)malloc(strlen(email));
		strcpy(n,email);
		this->email =n;
	}else{
		this->email=NULL;
	}	
	this->mec_number = mec_number;
}

void Teacher_toString(Teacher* this){
	printf ("Number: %d\tName: %s\tEmail: %s\n",this->mec_number,this->name,this->email);
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

