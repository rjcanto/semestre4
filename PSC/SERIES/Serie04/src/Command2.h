#ifndef COMMAND2_H
#define COMMAND2_H
#include "Command.h"
#include "Commands.h"

typedef struct com2 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command2;

Command2* Command2_ctor();
void Command2_init(Command2* this);
void Command2_clear(Command2* this);
void Command2_dtor(Command2* this);

/*Para a Construção da Base de Dados*/
void Command2_createDB(Command2* this);
void Command2_destroyDB(Command2* this);
void Command2_insert_CDB(Command2* this,void* t);

void Command2_parseLine(char* line);

/*Para a Query*/
void Command2_queryCDB1(Command2* this,char* key);

#endif
