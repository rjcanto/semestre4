#include "ExitCmd.h"


void  ExitCmd_exec(ExitCmd* this,char* txt){
		puts(this->description);
		this->super.gvptr->exit();
		puts("Bye");		
}

void  ExitCmd_help(ExitCmd* this){puts(this->help);}
char  ExitCmd_prefix(ExitCmd* this){return this->prefix;}

void ExitCmd_cleanup(ExitCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void ExitCmd_delete(ExitCmd* this){
	if (this == NULL) return;
	ExitCmd_cleanup(this);
	free(this);
}

const static Command_Methods exitcmd_vTable={
	(const void (*) (Command*)) ExitCmd_delete,
	(const char (*) (Command*))			ExitCmd_prefix,
	(const void (*) (Command*,char*))	ExitCmd_exec,
	(const void (*) (Command*))			ExitCmd_help,
	(const char*(*) (Command*))			Command_syntax
};


void ExitCmd_init(ExitCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr=&exitcmd_vTable;
	this->description = (char*)malloc(strlen("The Exit Command!")+1);
	strcpy(this->description,"The Exit Command!");
	
	this->help = (char*)malloc(strlen("Terminate the game.")+1);
	strcpy(this->help,"Terminate the game.");

	this->prefix		= 'E';
}
ExitCmd* ExitCmd_new(Game_Methods* gvptr){
	ExitCmd* this = (ExitCmd*)malloc(sizeof(ExitCmd));
	ExitCmd_init(this,gvptr);
	return this;
}


Command* newInstance(Game_Methods* gvptr) {return (Command*) ExitCmd_new(gvptr);}
