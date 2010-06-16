#ifndef COMMAND3_H
#define COMMAND3_H
#include "Command.h"
#include "Commands.h"

typedef struct com3 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command3;

Command3* Command3_ctor();
void Command3_init(Command3* this);
void Command3_clear(Command3* this);
void Command3_dtor(Command3* this);

/*Para a Construção da Base de Dados*/
void Command3_createDB(Command3* this);
void Command3_destroyDB(Command3* this);
void Command3_insert_CDB(Command3* this,void* t);

void Command3_parseLine(char* line);

/*Para a Query*/
void Command3_queryCDB1(Command3* this,char* key);

#endif
