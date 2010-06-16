#ifndef COMMAND7_H
#define COMMAND7_H
#include "Command.h"
#include "Commands.h"

typedef struct com7 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command7;

Command7* Command7_ctor();
void Command7_init(Command7* this);
void Command7_clear(Command7* this);
void Command7_dtor(Command7* this);

/*Para a Construção da Base de Dados*/
void Command7_createDB(Command7* this);
void Command7_destroyDB(Command7* this);
void Command7_insert_CDB(Command7* this,void* t);

void Command7_parseLine(char* line);

/*Para a Query*/
void Command7_queryCDB1(Command7* this,char* key);


#endif
