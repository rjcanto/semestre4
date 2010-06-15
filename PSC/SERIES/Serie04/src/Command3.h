#ifndef COMMAND3_H
#define COMMAND3_H
#include "Command.h"
/*Para a Construção da Base de Dados*/
void Command3_createDB();
void Command3_destroyDB();
void Command3_insert_CDB(void * this);


/*
void Command3_parseLine(char* line);
void Command3_getLine(CDBLF * result,void* this );
*/
/*Para a Query*/
void Command3_queryCDB1(char* key);


#endif
