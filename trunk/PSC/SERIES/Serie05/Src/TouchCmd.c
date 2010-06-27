#include "TouchCmd.h"

void  TouchCmd_exec(TouchCmd* this,char* txt){
		int l = Command_parseLine(txt);
		int c = Command_parseCol(txt);
		
		printf("%d < - > %d", l, c);
		
		/*
		Minesweeper.board.touch(l, c);
		if (Minesweeper.board.isSolved()) {
			System.out.println("You WIN.");
			Minesweeper.board.showAll();
		}*/
}

char* TouchCmd_syntax(TouchCmd* this){return this->syntax;}
void  TouchCmd_help(TouchCmd* this){puts(this->help);}
char  TouchCmd_prefix(TouchCmd* this){return this->prefix;}


const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) TouchCmd_cleanup,
	(const char (*) ())			TouchCmd_prefix,
	(const void (*) (char*))	TouchCmd_exec,
	(const void (*) ())			TouchCmd_help,
	(const char*(*) ())		TouchCmd_syntax
};


void TouchCmd_init(TouchCmd* this){
	Command_init(&(this->super));
	this->super.vptr=&touchcmd_vTable;
	this->description = (char*)malloc(strlen("The Touch Command!")+1);
	strcpy(this->description,"The Touch Command!");
	
	this->syntax = (char*)malloc(strlen("<lin><col>")+1);
	strcpy(this->syntax,"<lin><col>");

	this->help = (char*)malloc(strlen("Touch a cell. BUMMM on bomb.")+1);
	strcpy(this->help,"Touch a cell. BUMMM on bomb.");

	this->prefix		= 'T';
}
TouchCmd* TouchCmd_new(){
	TouchCmd* this = (TouchCmd*)malloc(sizeof(TouchCmd));
	TouchCmd_init(this);
	return this;
}

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

Command* newInstance(void) {return (Command*) TouchCmd_new();}


