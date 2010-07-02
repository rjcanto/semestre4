#ifndef TOUCHCMD_H
#define TOUCHCMD_H
#include "Command.h"
struct touchcmd;
typedef struct touchcmd TouchCmd;

struct touchcmd{
	Command super;
	char* 	description;
	char*	syntax;
	char*	help;
	char	prefix;
};
	char 	TouchCmd_prefix(TouchCmd* this);
	char* 	TouchCmd_syntax(TouchCmd* this);
	void 	TouchCmd_exec(TouchCmd* this,char* line);
	void 	TouchCmd_help(TouchCmd* this);
	void 	TouchCmd_cleanup(TouchCmd* this);
#endif
