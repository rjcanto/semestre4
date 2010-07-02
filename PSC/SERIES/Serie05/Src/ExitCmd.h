#ifndef EXITCMD_H
#define EXITCMD_H
#include "Command.h"
#include "Command_UP_Interface.h"
struct exitcmd;
typedef struct exitcmd ExitCmd;

struct exitcmd{
	Command super;
	char* 	description;
	char	prefix;
	char*	help;
};
	char 	ExitCmd_prefix(ExitCmd* this);
	void 	ExitCmd_exec(ExitCmd* this,char* line);
	void 	ExitCmd_help(ExitCmd* this);
	void 	ExitCmd_cleanup(ExitCmd* this);
#endif
