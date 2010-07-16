#ifndef SAVECMD_H
#define SAVECMD_H
#include "CommandInterface.h"
#include "Command.h"
struct savecmd;
typedef struct savecmd SaveCmd;

struct savecmd{
	Command super;
	char* 	description;
	char	prefix;
	char*	help;
};
	char 	SaveCmd_prefix(SaveCmd* this);
	void 	SaveCmd_exec(SaveCmd* this,char* line);
	void 	SaveCmd_help(SaveCmd* this);
	char* 	SaveCmd_syntax(SaveCmd* this);
	void 	SaveCmd_cleanup(SaveCmd* this);
#endif
