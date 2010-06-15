#ifndef COMMAND7_H
#define COMMAND7_H
#include "Command.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "Command6.h"
#include "UniCurr.h"
#include "Teacher.h"
/*Para a Construção da Base de Dados*/
void Command7_createDB();
void Command7_destroyDB();
void Command7_insert_CDB(void * this);


/*
void Command7_parseLine(char* line);
void Command7_getLine(CDBLF * result,void* this );
*/
/*Para a Query*/
void Command7_queryCDB1(char* key);



#endif
