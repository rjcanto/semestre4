#ifndef NEWCMD_H
#define NEWCMD_H
#include "Command.h"
struct newcmd;
typedef struct newcmd NewCmd;

struct newcmd{
	Command super;
	char* 	description;
	char	prefix;
	char*	syntax;
	char*	help;
};
	char 	HelpCmd_prefix(NewCmd* this);
	char* 	HelpCmd_syntax(NewCmd* this);
	void 	HelpCmd_exec(NewCmd* this,char* line);
	void 	HelpCmd_help(NewCmd* this);
	void 	HelpCmd_cleanup(NewCmd* this);

#endif
