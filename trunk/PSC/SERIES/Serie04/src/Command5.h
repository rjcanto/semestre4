#ifndef COMMAND5_H
#define COMMAND5_H
#include "Command.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "UniCurr.h"
#include "Teacher.h"
/*Para a Construção da Base de Dados*/
void Command5_createDB();
void Command5_destroyDB();
void Command5_insert_CDB(void * this);


/*
void Command5_parseLine(char* line);
void Command5_getLine(CDBLF * result,void* this );
*/
/*Para a Query*/
void Command5_queryCDB1(char* key);



#endif
