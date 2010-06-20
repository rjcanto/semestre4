#ifndef COMMAND10_H
#define COMMAND10_H
#include "Command.h"
#include "Commands.h"
#define BUFFER_SIZE 100
#define C10_COMMANDS_NBR 10
#define C10_MIN_COMMAND	2
#define C10_MAX_COMMAND 7

typedef struct com10 {
	Command super;
	Command* myCommand[C10_COMMANDS_NBR];
} Command10;

Command10* Command10_ctor();
void Command10_init(Command10* this);
void Command10_clear(Command10* this);
void Command10_dtor(Command10* this);

/*Para a Construção da Base de Dados*/
void Command10_createDB(Command10* this);
void Command10_destroyDB(Command10* this);
void Command10_insert_CDB(Command10* this,void* t);
void Command10_parseLine(char* line);

/*Para a Query*/
void Command10_queryCDB1(Command10* this,char* key);



#endif
