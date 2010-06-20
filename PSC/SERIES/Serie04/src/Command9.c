#include "Command9.h"


static void createDB(Command9* this){
	int idx;
	for(idx=C9_MIN_COMMAND;idx<=C9_MAX_COMMAND;++idx){
		if(this->myCommand[idx] != NULL){
			this->myCommand[idx]->vptr->createDB(this->myCommand[idx]);
		}
	}
}
static void insertDB(Command9* this,void* element){
	int idx;
	for(idx=C9_MIN_COMMAND;idx<=C9_MAX_COMMAND;++idx){
		if(this->myCommand[idx] != NULL)
			this->myCommand[idx]->vptr->insertDB(this->myCommand[idx],element);
	}
}
static void closeDB(Command9* this){
	int idx;
	for(idx=C9_MIN_COMMAND;idx<=C9_MAX_COMMAND;++idx){
		if(this->myCommand[idx] != NULL)
			this->myCommand[idx]->vptr->destroyDB(this->myCommand[idx]);
	}	
}

void Command9_execute(Command9* this, char* filename){
	FILE* fp= fopen(filename, "rb");
	Teacher * teacher;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';

	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}

	createDB(this);
	
	printf("Processing the file");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		printf(".");
		/*Aloc de Unidade Curricular*/
		teacher = Teacher_new_fromString(buffer,delimiter);
		
		insertDB(this,teacher);

		/*Free de Unidade Curricular*/
		Teacher_destroy(teacher);
		teacher=NULL;
	}
	puts("Finished!");
	closeDB(this);

	

	fclose(fp);
}
void Command9_createDB(Command9* this){
	puts("Method Not Implemented.");
}
void Command9_destroyDB(Command9* this){
	puts("Method Not Implemented.");
}
void Command9_insert_CDB(Command9* this,void* t){
	puts("Method Not Implemented.");
}
void Command9_parseLine(char* line){
	puts("Method Not Implemented.");
}
void Command9_queryCDB1(Command9* this,char* key){
	puts("Method Not Implemented.");
}



static const Command_Methods Command9_vtable = {
	(void (*)(void*)) Command9_dtor,
	(void (*)(void*)) Command9_createDB,
	(void (*)(void*)) Command9_destroyDB,
	(void (*)(void*,void*)) Command9_insert_CDB,
	(void (*)(char*)) Command9_parseLine,
	(void (*)(void*, char*) )Command9_execute,
	"Processamento do Ficheiro de Docentes, criando as bases de dados constantes necessárias.",
	'i'
};

Command9* Command9_ctor(){
	Command9* this=(Command9*)malloc(sizeof(Command9));
	Command9_init(this);
	return this;
}

void Command9_init(Command9* this){
	if (this == NULL)return;
	this->super.vptr = &Command9_vtable;
	this->myCommand[0]=(Command*)Command2_ctor();
	this->myCommand[1]=(Command*)Command3_ctor();
	this->myCommand[2]=(Command*)Command1_ctor();
	this->myCommand[3]=(Command*)Command4_ctor();
	this->myCommand[4]=(Command*)Command5_ctor();
	this->myCommand[5]=(Command*)Command6_ctor();
	this->myCommand[6]=(Command*)Command7_ctor();
	this->myCommand[7]=(Command*)Command8_ctor();
}
void Command9_clear(Command9* this){
	int idx;
	if (this == NULL) return;
	for(idx=0;idx<=7;++idx){
		if(this->myCommand[idx] != NULL)
			this->myCommand[idx]->vptr->dtor(this->myCommand[idx]);
	}
}

void Command9_dtor(Command9* this){
	if(this != NULL)
		Command9_clear(this);
	free(this);
}



