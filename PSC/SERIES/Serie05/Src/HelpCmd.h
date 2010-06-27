#ifndef HELPCMD_H
#define HELPCMD_H
#include "Command.h"
struct helpcmd;
typedef struct helpcmd HelpCmd;

struct helpcmd{
	Command super;
	char* 	description;
	char	prefix;
	char*	syntax;
	char*	help;
};
	char 	HelpCmd_prefix(HelpCmd* this);
	char* 	HelpCmd_syntax(HelpCmd* this);
	void 	HelpCmd_exec(HelpCmd* this,char* line);
	void 	HelpCmd_help(HelpCmd* this);
	void 	HelpCmd_cleanup(HelpCmd* this);
#endif
