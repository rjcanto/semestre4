#ifndef COMMAND4_H
#define COMMAND4_H
#include "Command.h"
#include "Commands.h"

typedef struct com4 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command4;

Command4* Command4_ctor();
void Command4_init(Command4* this);
void Command4_clear(Command4* this);
void Command4_dtor(Command4* this);

/*Para a Construção da Base de Dados*/
void Command4_createDB(Command4* this);
void Command4_destroyDB(Command4* this);
void Command4_insert_CDB(Command4* this,void* t);

void Command4_parseLine(char* line);

/*Para a Query*/
void Command4_queryCDB1(Command4* this,char* key);
#endif
