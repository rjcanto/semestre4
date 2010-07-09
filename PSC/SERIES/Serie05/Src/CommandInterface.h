#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H
#include "newtypes.h"
struct command;
typedef struct command Command;


typedef struct command_methods{
	const void		(*dtor)		(Command* this);
	const char 		(*prefix)	(Command* this);
	const void 		(*exec)		(Command*, char* line);
	const void 		(*help)		(Command* this);
	const char* 	(*syntax)	(Command* this);
}Command_Methods;



#endif
