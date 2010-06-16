#ifndef COMMAND6_H
#define COMMAND6_H
#include "Command.h"
#include "Commands.h"

typedef struct com6 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command6;

Command6* Command6_ctor();
void Command6_init(Command6* this);
void Command6_clear(Command6* this);
void Command6_dtor(Command6* this);

/*Para a Construção da Base de Dados*/
void Command6_createDB(Command6* this);
void Command6_destroyDB(Command6* this);
void Command6_insert_CDB(Command6* this,void* t);

void Command6_parseLine(char* line);

/*Para a Query*/
void Command6_queryCDB1(Command6* this,char* key);




#endif
