#ifndef COMMAND8_H
#define COMMAND8_H
#include "Command.h"
#include "Command1.h"

/*Para a Construção da Base de Dados*/
void Command8_createDB();
void Command8_destroyDB();
void Command8_insert_CDB(void * this);

void Command8_parseLine(char* line);

/*
void Command8_getLine(CDBLF * result,void* this );
*/
/*Para a Query*/
void Command8_queryCDB1(char* key);



#endif
