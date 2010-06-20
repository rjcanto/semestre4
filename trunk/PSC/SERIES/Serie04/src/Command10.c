#include "Command10.h"
static void createDB(Command10* this){
	int idx;
	for(idx=C10_MIN_COMMAND;idx<=C10_MAX_COMMAND;++idx){
		if(this->myCommand[idx] != NULL){
			this->myCommand[idx]->vptr->createDB(this->myCommand[idx]);
		}
	}
}
static void insertDB(Command10* this,void* element){
	int idx;
	for(idx=C10_MIN_COMMAND;idx<=C10_MAX_COMMAND;++idx){
		if(this->myCommand[idx] != NULL)
			this->myCommand[idx]->vptr->insertDB(this->myCommand[idx],element);
	}
}
static void closeDB(Command10* this){
	int idx;
	for(idx=C10_MIN_COMMAND;idx<=C10_MAX_COMMAND;++idx){
		if(this->myCommand[idx] != NULL)
			this->myCommand[idx]->vptr->destroyDB(this->myCommand[idx]);
	}	
}

void Command10_execute(Command10* this, char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';

	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}

	createDB(this);
	
	printf("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		printf(".");
		/*Aloc de Unidade Curricular*/
		unicurr = UniCurr_new_fromString(buffer,delimiter);
		
		insertDB(this,unicurr);

		/*Free de Unidade Curricular*/
		UniCurr_destroy(unicurr);
		unicurr=NULL;
	}
	puts("Finished!");
	closeDB(this);

	

	fclose(fp);
}
void Command10_createDB(Command10* this){
	puts("Method Not Implemented.");
}
void Command10_destroyDB(Command10* this){
	puts("Method Not Implemented.");
}
void Command10_insert_CDB(Command10* this,void* t){
	puts("Method Not Implemented.");
}
void Command10_parseLine(char* line){
	puts("Method Not Implemented.");
}
void Command10_queryCDB1(Command10* this,char* key){
	puts("Method Not Implemented.");
}



static const Command_Methods Command10_vtable = {
	(void (*)(void*)) Command10_dtor,
	(void (*)(void*)) Command10_createDB,
	(void (*)(void*)) Command10_destroyDB,
	(void (*)(void*,void*)) Command10_insert_CDB,
	(void (*)(char*)) Command10_parseLine,
	(void (*)(void*, char*) )Command10_execute,
	"Processamento do ficheiro de Unidades Curriculares, criando as bases de dados constantes necessárias.",
	'j'
};

Command10* Command10_ctor(){
	Command10* this=(Command10*)malloc(sizeof(Command10));
	Command10_init(this);
	return this;
}

void Command10_init(Command10* this){
	if (this == NULL)return;
	this->super.vptr = &Command10_vtable;
	this->myCommand[0]=(Command*)Command2_ctor();
	this->myCommand[1]=(Command*)Command3_ctor();
	this->myCommand[2]=(Command*)Command1_ctor();
	this->myCommand[3]=(Command*)Command4_ctor();
	this->myCommand[4]=(Command*)Command5_ctor();
	this->myCommand[5]=(Command*)Command6_ctor();
	this->myCommand[6]=(Command*)Command7_ctor();
	this->myCommand[7]=(Command*)Command8_ctor();

	
}
void Command10_clear(Command10* this){
	int idx;
	if (this == NULL) return;

	for(idx=0;idx<=7;++idx){
		if(this->myCommand[idx] != NULL)
			this->myCommand[idx]->vptr->dtor(this->myCommand[idx]);
	}
}

void Command10_dtor(Command10* this){
	if(this != NULL)
		Command10_clear(this);
	free(this);
}



