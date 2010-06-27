#include "NewCmd.h"

void  NewCmd_exec(NewCmd* this,char* txt){
	/*Minesweeper.board=new Board();*/
}

void  NewCmd_help(NewCmd* this){puts(this->help);}
char  NewCmd_prefix(NewCmd* this){return this->prefix;}

void NewCmd_cleanup(NewCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->syntax);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void NewCmd_delete(NewCmd* this){
	if (this == NULL) return;
	NewCmd_cleanup(this);
	free(this);
}


const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) NewCmd_cleanup,
	(const char (*) ())			NewCmd_prefix,
	(const void (*) (char*))	NewCmd_exec,
	(const void (*) ())			NewCmd_help,
	(const char*(*) ())			Command_syntax
};


void NewCmd_init(NewCmd* this){
	Command_init(&(this->super));
	this->super.vptr=&touchcmd_vTable;
	this->description = (char*)malloc(strlen("The New Command!")+1);
	strcpy(this->description,"The New Command!");
	
	this->help = (char*)malloc(strlen("Create a new board.")+1);
	strcpy(this->help,"Create a new board.");

	this->prefix		= 'N';
}
NewCmd* NewCmd_new(){
	NewCmd* this = (NewCmd*)malloc(sizeof(NewCmd));
	NewCmd_init(this);
	return this;
}

Command* newInstance(void) {return (Command*) NewCmd_new();}




