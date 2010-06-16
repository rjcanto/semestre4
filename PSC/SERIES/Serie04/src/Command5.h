#ifndef COMMAND5_H
#define COMMAND5_H
#include "Command.h"
#include "Commands.h"

typedef struct com5 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command5;

Command5* Command5_ctor();
void Command5_init(Command5* this);
void Command5_clear(Command5* this);
void Command5_dtor(Command5* this);

/*Para a Construção da Base de Dados*/
void Command5_createDB(Command5* this);
void Command5_destroyDB(Command5* this);
void Command5_insert_CDB(Command5* this,void* t);

void Command5_parseLine(char* line);

/*Para a Query*/
void Command5_queryCDB1(Command5* this,char* key);



#endif
