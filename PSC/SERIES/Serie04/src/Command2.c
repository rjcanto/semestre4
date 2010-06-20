#include "Command2.h"

void Command2_clear(Command2* this){
	this->filename=NULL;
	this->fd=0;
}

void Command2_dtor(Command2* this){
	if(this != NULL)
		Command2_clear(this);
	free(this);
}

void Command2_createDB(Command2* this){
	puts("Method Not Implemented. This only a 'list all' command.");
}

void Command2_insert_CDB(Command2* this,void* t){
	puts("Method Not Implemented. This only a 'list all' command.");
}


void Command2_queryCDB1(Command2* this,char* key){
	Command1* c1=Command1_ctor();
	Command3* c3=Command3_ctor();
	FILE* fp= fopen(c1->filename, "rb");
	if (fp == NULL){
		fprintf(stderr, "Unable to open the file. Please check the file, or build de database again!\n");
		c1->super.vptr->dtor(c1);
		exit(2);	
	}
	fclose(fp);
	fp= fopen(c3->filename, "rb");
	if (fp == NULL){
		fprintf(stderr, "Unable to open the file. Please check the file, or build de database again!\n");
		c3->super.vptr->dtor(c3);
		exit(2);	
	}
	fclose(fp);
	printf("Processing Unidades Curriculares\n");
	Command_dbReader(c1->filename,"",Command_dblistAll,c1->super.vptr->lineParser);
	puts("Press Enter to continue...");getchar();
	printf("Processing Docentes\n");
	Command_dbReader(c3->filename,"",Command_dblistAll,c3->super.vptr->lineParser);
	c1->super.vptr->dtor(c1);
	c3->super.vptr->dtor(c3);
}

void Command2_destroyDB(Command2* this){
	puts("Method Not Implemented. This only a 'list all' command.");
}
void Command2_parseLine(char* line){
	puts("Method Not Implemented. This only a 'list all' command.");
}

static const Command_Methods Command2_vtable = {
	(void (*)(void*)) Command2_dtor,
	(void (*)(void*)) Command2_createDB,
	(void (*)(void*)) Command2_destroyDB,
	(void (*)(void*,void*)) Command2_insert_CDB,
	(void (*)(char*)) Command2_parseLine,
	(void (*)(void*, char*) )Command2_queryCDB1,
	"Lista Todos as entradas da Base de dados de Unidades Curriculares e Professores.",
	'a'
};


Command2* Command2_ctor(){
	Command2* this=(Command2*)malloc(sizeof(Command2));
	Command2_init(this);
	return this;
}

void Command2_init(Command2* this){
	this->super.vptr= &Command2_vtable;
}



