#include "HelpCmd.h"

void  HelpCmd_exec(HelpCmd* this,char* txt){
	Command* c;
	int i;
	for (i=0;i< Commands_Array.length;++i){
		c = (Commands_Array.cmds + i*(sizeof(Command)));
		printf("%c%s :\n",c->vptr->prefix() ,c->vptr->syntax());
		c->vptr->help();
	}
}

void  HelpCmd_help(HelpCmd* this){puts(this->help);}
char  HelpCmd_prefix(HelpCmd* this){return this->prefix;}

void HelpCmd_cleanup(HelpCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->syntax);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void HelpCmd_delete(HelpCmd* this){
	if (this == NULL) return;
	HelpCmd_cleanup(this);
	free(this);
}

const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) HelpCmd_cleanup,
	(const char (*) ())			HelpCmd_prefix,
	(const void (*) (char*))	HelpCmd_exec,
	(const void (*) ())			HelpCmd_help,
	(const char*(*) ())			Command_syntax
};


void HelpCmd_init(HelpCmd* this){
	Command_init(&(this->super));
	this->super.vptr=&touchcmd_vTable;
	this->description = (char*)malloc(strlen("The Help Command!")+1);
	strcpy(this->description,"The Help Command!");
	
	this->help = (char*)malloc(strlen("Help for all commands.")+1);
	strcpy(this->help,"Help for all commands.");

	this->prefix		= 'H';
}
HelpCmd* HelpCmd_new(){
	HelpCmd* this = (HelpCmd*)malloc(sizeof(HelpCmd));
	HelpCmd_init(this);
	return this;
}


Command* newInstance(void) {return (Command*) HelpCmd_new();}



