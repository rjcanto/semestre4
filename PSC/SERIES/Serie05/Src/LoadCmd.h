#ifndef LOADCMD_H
#define LOADCMD_H
#include "Command.h"
struct loadcmd;
typedef struct loadcmd LoadCmd;

struct loadcmd{
	Command super;
	char* 	description;
	char	prefix;
	char*	help;
};
	char 	LoadCmd_prefix(LoadCmd* this);
	void 	LoadCmd_exec(LoadCmd* this,char* line);
	void 	LoadCmd_help(LoadCmd* this);
	char* 	LoadCmd_syntax(LoadCmd* this);
	void 	LoadCmd_cleanup(LoadCmd* this);
#endif
