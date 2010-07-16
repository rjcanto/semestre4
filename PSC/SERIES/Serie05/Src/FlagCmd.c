#include "FlagCmd.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
 * Executa o Comando
 * */
void  FlagCmd_exec(FlagCmd* this,char* txt){
		int l = Command_parseLine(txt);
		int c = Command_parseCol(txt);
		
		this->super.gvptr->flag(l,c);
		if (this->super.gvptr->isSolved()){
			puts("You Win");
			this->super.gvptr->showAll();
		}

}
/**
 * Devolve a sintaxe do comando
 * */
char* FlagCmd_syntax(FlagCmd* this){return this->syntax;}
/**
 * Mostra a ajuda para o comando
 * */
void  FlagCmd_help(FlagCmd* this){
	printf("[%c] - %s\n",this->prefix,this->description);
	puts(this->help);
}
/**
 * Devolve o prefixo do comando
 * */
char  FlagCmd_prefix(FlagCmd* this){return this->prefix;}

/**
 * Destrutores/Construtores e afins
 * */
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


/**
 * Devolve uma nova instancia de Comando para ser carregado dinamicamente
 * */
Command* newInstance(Game_Methods* gvptr) {return (Command*) FlagCmd_new(gvptr);}


