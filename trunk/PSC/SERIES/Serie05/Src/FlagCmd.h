#ifndef FLAGCMD_H
#define FLAGCMD_H
#include "Command.h"
struct flagcmd;
typedef struct flagcmd FlagCmd;

struct flagcmd{
	Command super;
	char* 	description;
	char	prefix;
	char*	syntax;
	char*	help;
};
	char 	FlagCmd_prefix(FlagCmd* this);
	char* 	FlagCmd_syntax(FlagCmd* this);
	void 	FlagCmd_exec(FlagCmd* this,char* line);
	void 	FlagCmd_help(FlagCmd* this);
	void 	FlagCmd_cleanup(FlagCmd* this);
#endif
