#ifndef COMMAND4_H
#define COMMAND4_H
#include "Command.h"
#include "Command1.h"
#include "UniCurr.h"
/*Para a Construção da Base de Dados*/
void Command4_createDB();
void Command4_destroyDB();
void Command4_insert_CDB(void * this);


/*
void Command4_parseLine(char* line);
void Command4_getLine(CDBLF * result,void* this );
*/
/*Para a Query*/
void Command4_queryCDB1(char* key);
#endif
