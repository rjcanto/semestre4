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
	char 	NewCmd_prefix(NewCmd* this);
	char* 	NewCmd_syntax(NewCmd* this);
	void 	NewCmd_exec(NewCmd* this,char* line);
	void 	NewCmd_help(NewCmd* this);
	void 	NewCmd_cleanup(NewCmd* this);

#endif
