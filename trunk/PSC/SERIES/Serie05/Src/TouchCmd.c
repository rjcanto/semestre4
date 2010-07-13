#include "TouchCmd.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void  TouchCmd_exec(TouchCmd* this,char* txt){
		int l = Command_parseLine(txt);
		int c = Command_parseCol(txt);
		
		this->super.gvptr->touch(l,c);
		if (this->super.gvptr->isSolved()){
			puts("You Win");
			this->super.gvptr->showAll();
		}

}

char* TouchCmd_syntax(TouchCmd* this){return this->syntax;}
void  TouchCmd_help(TouchCmd* this){
	printf("[%c] - %s\n",this->prefix,this->description);
	puts(this->help);
}
char  TouchCmd_prefix(TouchCmd* this){return this->prefix;}

void TouchCmd_cleanup(TouchCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->syntax);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void TouchCmd_delete(TouchCmd* this){
	if (this == NULL) return;
	TouchCmd_cleanup(this);
	free(this);
}
const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) TouchCmd_delete,
	(const char (*) (Command*))			TouchCmd_prefix,
	(const void (*) (Command*,char*))	TouchCmd_exec,
	(const void (*) (Command*))			TouchCmd_help,
	(const char*(*) (Command*))			TouchCmd_syntax
};


void TouchCmd_init(TouchCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr = &touchcmd_vTable;
	this->description = (char*)malloc(strlen("The Touch Command!")+1);
	strcpy(this->description,"The Touch Command!");
	
	this->syntax = (char*)malloc(strlen("<lin><col>")+1);
	strcpy(this->syntax,"<lin><col>");
	this->help = (char*)malloc(strlen("Touch a cell. BUMMM on bomb.")+1);
	strcpy(this->help,"Touch a cell. BUMMM on bomb.");
	this->prefix		= 'T';

}
TouchCmd* TouchCmd_new(Game_Methods* gvptr){
	TouchCmd* this = (TouchCmd*)malloc(sizeof(TouchCmd));
	TouchCmd_init(this,gvptr);
	return this;
}



Command* newInstance(Game_Methods* gvptr) {return (Command*) TouchCmd_new(gvptr);}


