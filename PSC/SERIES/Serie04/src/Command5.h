#ifndef COMMAND5_H
#define COMMAND5_H
#include "Command.h"
#include "Command3.h"

/*Para a Construção da Base de Dados*/
void Command5_createDB();
void Command5_destroyDB();
void Command5_insert_CDB(void * this);


void Command5_parseLine(char* line);

/*Para a Query*/
void Command5_queryCDB1(char* key);



#endif
