#ifndef COMMAND1_H
#define COMMAND1_H
#include "Command.h"
#include "Commands.h"

typedef struct com1 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command1;

Command1* Command1_ctor();
void Command1_init(Command1* this);
void Command1_clear(Command1* this);
void Command1_dtor(Command1* this);

/*Para a Construção da Base de Dados*/
void Command1_createDB(Command1* this);
void Command1_destroyDB(Command1* this);
void Command1_insert_CDB(Command1* this,void* t);

void Command1_parseLine(char* line);

/*Para a Query*/
void Command1_queryCDB1(Command1* this,char* key);



#endif
