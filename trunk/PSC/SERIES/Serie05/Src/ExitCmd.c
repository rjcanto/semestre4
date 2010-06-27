#include "ExitCmd.h"
void  ExitCmd_exec(ExitCmd* this,char* txt){
		puts("Bye.");
		/*
		Minesweeper.exit=true;
		*/
}

void  ExitCmd_help(ExitCmd* this){puts(this->help);}
char  ExitCmd_prefix(ExitCmd* this){return this->prefix;}


const static Command_Methods exitcmd_vTable={
	(const void (*) (Command*)) ExitCmd_cleanup,
	(const char (*) ())			ExitCmd_prefix,
	(const void (*) (char*))	ExitCmd_exec,
	(const void (*) ())			ExitCmd_help,
	(const char*(*) ())			Command_syntax
};


void ExitCmd_init(ExitCmd* this){
	Command_init(&(this->super));
	this->super.vptr=&exitcmd_vTable;
	this->description = (char*)malloc(strlen("The Exit Command!")+1);
	strcpy(this->description,"The Exit Command!");
	
	this->help = (char*)malloc(strlen("Terminate the game.")+1);
	strcpy(this->help,"Terminate the game.");

	this->prefix		= 'E';
}
ExitCmd* ExitCmd_new(){
	ExitCmd* this = (ExitCmd*)malloc(sizeof(ExitCmd));
	ExitCmd_init(this);
	return this;
}

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
Command* newInstance(void) {return (Command*) ExitCmd_new();}
