#include "HelpCmd.h"
extern Cmds Commands_Array;

void  HelpCmd_exec(HelpCmd* this,char* txt){
	Command* c;
	int i;
	puts(this->description);
	printf(":::%d\n",Commands_Array.length);
	for (i=0;i< Commands_Array.length;++i){
		c = Commands_Array.cmds[i];
		printf("%c%s :\n",c->vptr->prefix(c) ,c->vptr->syntax(c));
		c->vptr->help(c);
	}
}

void  HelpCmd_help(HelpCmd* this){puts(this->help);}
char  HelpCmd_prefix(HelpCmd* this){return this->prefix;}

void HelpCmd_cleanup(HelpCmd* this){
	if (this == NULL) return;
	Command_cleanup(&(this->super));
	free(this->help);
	free(this->description);
	this->prefix=0;
}
void HelpCmd_delete(HelpCmd* this){
	if (this == NULL) return;
	HelpCmd_cleanup(this);
	free(this);
}

const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) HelpCmd_delete,
	(const char (*) (Command*))			HelpCmd_prefix,
	(const void (*) (Command*,char*))	HelpCmd_exec,
	(const void (*) (Command*))			HelpCmd_help,
	(const char*(*) (Command*))			Command_syntax
};


void HelpCmd_init(HelpCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr=&touchcmd_vTable;
	this->description = (char*)malloc(strlen("The Help Command!")+1);
	strcpy(this->description,"The Help Command!");
	
	this->help = (char*)malloc(strlen("Help for all commands.")+1);
	strcpy(this->help,"Help for all commands.");

	this->prefix		= 'H';
}
HelpCmd* HelpCmd_new(Game_Methods* gvptr){
	HelpCmd* this = (HelpCmd*)malloc(sizeof(HelpCmd));
	HelpCmd_init(this,gvptr);
	return this;
}


Command* newInstance(Game_Methods* gvptr) {return (Command*) HelpCmd_new(gvptr);}



