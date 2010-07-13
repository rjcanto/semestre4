#include "Command.h"
#include "newtypes.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const static Command_Methods cmd_vtable={
	(const void (*) (Command*)) Command_cleanup,
	(const char (*) (Command*))Command_prefix,
	(const void (*) (Command*,char*))Command_exec,
	(const void (*) (Command*))Command_help,
	(const char*(*) (Command*))Command_syntax
};

char 	Command_prefix(Command* this){
	puts("Method Command_prefix not yet implemeted!");
	return 0;
}
char* 	Command_syntax(Command* this){
	return ""; 

}
void 	Command_exec(Command* this,char* line){
	puts("Method Command_exec not yet implemeted!");	
}
void 	Command_help(Command* this){
	puts("Method Command_help not yet implemeted!");
}

int Command_parseCol(char* txt){
	int val=0;
	char c;

	while (*txt && (toupper(*txt) < 'A' || toupper(*txt)>'Z'))
		++txt;
	
	if (*txt && toupper(*txt) >= 'A' && toupper(*txt)<='Z' ) {c=toupper(*txt); val+=c-'A'; }
	return val;	
}
int Command_parseLine(char* txt){
	int val=0;
	char c;

	while(*txt && (*txt <= '0' || *txt>='9'))
		++txt;
	
	while(*txt && *txt >= '0' && *txt<='9'){
		c=*(txt++);
		val*=10; val+=c-'0';			
	}
	return val-1;		
}



void Command_init(Command* t,Game_Methods* gvptr){
	t->vptr= &cmd_vtable;
	t->gvptr=gvptr;
}
void Command_cleanup(Command* t){
	t->vptr = NULL;
	
}
