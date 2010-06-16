#ifndef COMMAND8_H
#define COMMAND8_H
#include "Command.h"
#include "Commands.h"

typedef struct com8 {
	Command super;
	char* 	filename;
	int 	fd;
	struct cdb_make cdbm;
} Command8;

Command8* Command8_ctor();
void Command8_init(Command8* this);
void Command8_clear(Command8* this);
void Command8_dtor(Command8* this);

/*Para a Construção da Base de Dados*/
void Command8_createDB(Command8* this);
void Command8_destroyDB(Command8* this);
void Command8_insert_CDB(Command8* this,void* t);

void Command8_parseLine(char* line);

/*Para a Query*/
void Command8_queryCDB1(Command8* this,char* key);



#endif
