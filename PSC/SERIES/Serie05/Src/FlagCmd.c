#include "FlagCmd.h"

void  FlagCmd_exec(FlagCmd* this,char* txt){
		int l = Command_parseLine(txt);
		int c = Command_parseCol(txt);
		
		this->super.gvptr->flag(l,c);
		if (this->super.gvptr->isSolved()){
			puts("You Win");
			this->super.gvptr->showAll();
		}
		/*
		Minesweeper.board.flag(l, c);
		if (Minesweeper.board.isSolved()) {
			System.out.println("You WIN.");
			Minesweeper.board.showAll();
		}*/
}

char* FlagCmd_syntax(FlagCmd* this){return this->syntax;}
void  FlagCmd_help(FlagCmd* this){puts(this->help);}
char  FlagCmd_prefix(FlagCmd* this){return this->prefix;}


void FlagCmd_cleanup(FlagCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->syntax);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void FlagCmd_delete(FlagCmd* this){
	if (this == NULL) return;
	FlagCmd_cleanup(this);
	free(this);
}
const static Command_Methods touchcmd_vTable={
	(const void (*) (Command*)) FlagCmd_delete,
	(const char (*) (Command*))			FlagCmd_prefix,
	(const void (*) (Command*,char*))	FlagCmd_exec,
	(const void (*) (Command*))			FlagCmd_help,
	(const char*(*) (Command*))		FlagCmd_syntax
};


void FlagCmd_init(FlagCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr=&touchcmd_vTable;
	this->description = (char*)malloc(strlen("The Flag Command!")+1);
	strcpy(this->description,"The Flag Command!");
	
	this->syntax = (char*)malloc(strlen("<lin><col>")+1);
	strcpy(this->syntax,"<lin><col>");

	this->help = (char*)malloc(strlen("Mark a cell with Bomb.")+1);
	strcpy(this->help,"Mark a cell with Bomb.");

	this->prefix		= 'F';
}
FlagCmd* FlagCmd_new(Game_Methods* gvptr){
	FlagCmd* this = (FlagCmd*)malloc(sizeof(FlagCmd));
	FlagCmd_init(this,gvptr);
	return this;
}


Command* newInstance(Game_Methods* gvptr) {return (Command*) FlagCmd_new(gvptr);}


