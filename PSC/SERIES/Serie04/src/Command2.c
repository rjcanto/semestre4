#include "Command2.h"
/**
 * - Criação de Base de Dados com a Informação das Unidade Curriculares
 * - Lista Todos as entradas da Base de dados
 * 
 * */

void Command2_clear(Command2* this){
	this->filename=NULL;
	this->fd=0;
	
}

void Command2_dtor(Command2* this){
	if(this != NULL)
		Command2_clear(this);
	free(this);
}
/*
char* Command2_filename="UCbyAcronimo.cdb";
struct cdb_make Command2_cdbm;
int fd;
*/
void Command2_createDB(Command2* this){
	puts("Method Not Implemented. This only a 'list all' command.");
}

void Command2_insert_CDB(Command2* this,void* t){
	puts("Method Not Implemented. This only a 'list all' command.");
}


void Command2_queryCDB1(Command2* this,char* key){
	Command1* c1=Command1_ctor();
	Command3* c3=Command3_ctor();
	
	Command_dbReader(c1->filename,"",Command_dblistAll,c1->super.vptr->lineParser);
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

const Command_Methods Command2_vtable = {
	(void (*)(void*)) Command2_dtor,
	(void (*)(void*)) Command2_createDB,
	(void (*)(void*)) Command2_destroyDB,
	(void (*)(void*,void*)) Command2_insert_CDB,
	(void (*)(char*)) Command2_parseLine,
	(void (*)(void*, char*) )Command2_queryCDB1,
	"Lista Todos as entradas da Base de dados",
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



