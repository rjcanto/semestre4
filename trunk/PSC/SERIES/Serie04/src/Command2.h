#ifndef COMMAND2_H
#define COMMAND_H
#include "Command.h"
#include "Command1.h"
#include "Command3.h"
/*Para a Construção da Base de Dados*/
void Command2_createDB();
void Command2_destroyDB();
void Command2_insert_CDB(void * this);

/*Para a Query*/
void Command2_queryCDB1(char* key);
#endif
