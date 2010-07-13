#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H
#include "newtypes.h"
#include "GameInterface.h"
struct command;
typedef struct command Command;


typedef struct command_methods{
	const void		(*dtor)		(Command* this);
	const char 		(*prefix)	(Command* this);
	const void 		(*exec)		(Command*, char* line);
	const void 		(*help)		(Command* this);
	const char* 	(*syntax)	(Command* this);
}Command_Methods;

struct command{
	const Command_Methods* 	vptr;
	const Game_Methods*	gvptr;
	void* handler;
};
typedef struct cmds_array{
	Command** cmds;
	int length;
}Cmds;


#endif
