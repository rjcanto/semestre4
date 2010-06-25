#ifndef COMMAND_H
#define COMMAND_H
#include "newtypes.h"
typedef struct command_methods{
	void	(*dtor)		(void* this);
	char 	(*prefix)	();
	void 	(*exec)		(String line);
	void 	(*help)		();
	char* 	(*syntax)	();
}Command_Methods;

typedef struct command{
	const Command_Methods* vptr;
}Command;

typedef struct cmd{
	const Command cmds[];
	const int length;
}Cmds;

	char 	Command_prefix();
	char* 	Command_syntax();
	void 	Command_exec(char* line);
	void 	Command_help();

	const Command cmds[];

	boolean Command_load(char* cfgFile);
	void 	Command_execute(char* line);
	const int Command_parseLine(char* txt);
	const int Command_parseCol(char* txt);
	
	void Command_dtor(void* this);
	Command* Command_ctor();
	void Command_init(void* this);
	void Command_clean(void* this);
	
#endif
