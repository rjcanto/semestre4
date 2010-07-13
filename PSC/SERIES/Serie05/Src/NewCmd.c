#include "NewCmd.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void  NewCmd_exec(NewCmd* this,char* txt){
	this->super.gvptr->newGame();
}

void  NewCmd_help(NewCmd* this){
	printf("[%c] - %s\n",this->prefix,this->description);
	puts(this->help);
}
char  NewCmd_prefix(NewCmd* this){return this->prefix;}

void NewCmd_cleanup(NewCmd* this){
	if (this == NULL) return;
	Command_cleanup(&(this->super));
	free(this->help);
	free(this->description);
	this->prefix=0;
}
void NewCmd_delete(NewCmd* this){
	if (this == NULL) return;
	NewCmd_cleanup(this);
	free(this);
}


const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) NewCmd_delete,
	(const char (*) (Command*))			NewCmd_prefix,
	(const void (*) (Command*,char*))	NewCmd_exec,
	(const void (*) (Command*))			NewCmd_help,
	(const char*(*) (Command*))			Command_syntax
};


void NewCmd_init(NewCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr=&touchcmd_vTable;
	this->description = (char*)malloc(strlen("The New Command!")+1);
	strcpy(this->description,"The New Command!");
	
	this->help = (char*)malloc(strlen("Create a new board.")+1);
	strcpy(this->help,"Create a new board.");

	this->prefix		= 'N';
}
NewCmd* NewCmd_new(Game_Methods* gvptr){
	NewCmd* this = (NewCmd*)malloc(sizeof(NewCmd));
	NewCmd_init(this,gvptr);
	return this;
}

Command* newInstance(Game_Methods* gvptr) {return (Command*) NewCmd_new(gvptr);}




