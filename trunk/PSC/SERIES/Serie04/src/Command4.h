#ifndef COMMAND4_H
#define COMMAND4_H
#include "Command.h"
#include "Command1.h"
/*Para a Construção da Base de Dados*/
void Command4_createDB();
void Command4_destroyDB();
void Command4_insert_CDB(void * this);


void Command4_parseLine(char* line);

/*Para a Query*/
void Command4_queryCDB1(char* key);
#endif
