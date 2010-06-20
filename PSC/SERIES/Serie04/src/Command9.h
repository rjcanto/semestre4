#ifndef COMMAND9_H
#define COMMAND9_H
#include "Command.h"
#include "Commands.h"
#define BUFFER_SIZE 100
#define C9_COMMANDS_NBR 10
#define C9_MIN_COMMAND	1
#define C9_MAX_COMMAND 1

typedef struct com9 {
	Command super;
	Command* myCommand[C9_COMMANDS_NBR];
} Command9;

Command9* Command9_ctor();
void Command9_init(Command9* this);
void Command9_clear(Command9* this);
void Command9_dtor(Command9* this);

/*Para a Construção da Base de Dados*/
void Command9_createDB(Command9* this);
void Command9_destroyDB(Command9* this);
void Command9_insert_CDB(Command9* this,void* t);

void Command9_parseLine(char* line);

/*Para a Query*/
void Command9_queryCDB1(Command9* this,char* key);



#endif
