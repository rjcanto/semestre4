#ifndef COMMAND1_H
#define COMMAND1_H
#include "Command.h"

/*Para a Construção da Base de Dados*/
void Command1_createDB();
void Command1_destroyDB();
void Command1_insert_CDB(void * this);

/*Para a Query*/
void Command1_queryCDB1(char* key);

#endif
