#ifndef COMMAND6_H
#define COMMAND6_H
#include "Command.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "UniCurr.h"
#include "Teacher.h"
/*Para a Construção da Base de Dados*/
void Command6_createDB();
void Command6_destroyDB();
void Command6_insert_CDB(void * this);


/*
void Command6_parseLine(char* line);
void Command6_getLine(CDBLF * result,void* this );
*/
/*Para a Query*/
void Command6_queryCDB1(char* key);


#endif
