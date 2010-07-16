#include "SaveCmd.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
 * Executa o Comando
 * */
void  SaveCmd_exec(SaveCmd* this,char* txt){
	char* str;
	if ((str = this->super.gvptr->save()) == NULL) {return;}
	else{
	FILE* fp=NULL;
	char* saveKey=(char*)calloc(strlen(str)+1+1,sizeof(char));
	char* cur=saveKey;
	unsigned char length=strlen(str);
	*saveKey++ = length ;
	puts("Saving game in MineSweeper.bin");
	for(;*str;++str,++saveKey)
		*saveKey = (*str)-15;
	
	fp=fopen("MineSweeper.bin","wb");
    fwrite(cur,sizeof(char),length+1,fp)    ;
	fclose(fp);
	puts("Done");
	free(saveKey=cur);
	}
}
/**
 * Mostra a ajuda para o comando
 * */
void  SaveCmd_help(SaveCmd* this){
	printf("[%c] - %s\n",this->prefix,this->description);
	puts(this->help);
}
/**
 * Devolve o prefixo do comando
 * */
char  SaveCmd_prefix(SaveCmd* this){return this->prefix;}
/**
 * Destrutores/Construtores e afins
 * */
void SaveCmd_cleanup(SaveCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void SaveCmd_delete(SaveCmd* this){
	if (this == NULL) return;
	SaveCmd_cleanup(this);
	free(this);
}

const static Command_Methods savecmd_vTable={
	(const void (*) (Command*)) SaveCmd_delete,
	(const char (*) (Command*))			SaveCmd_prefix,
	(const void (*) (Command*,char*))	SaveCmd_exec,
	(const void (*) (Command*))			SaveCmd_help,
	(const char*(*) (Command*))			Command_syntax
};


void SaveCmd_init(SaveCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr=&savecmd_vTable;
	this->description = (char*)malloc(strlen("The Save Command!")+1);
	strcpy(this->description,"The Save Command!");
	
	this->help = (char*)malloc(strlen("Save the current point of the game.")+1);
	strcpy(this->help,"Save the current point of the game.");

	this->prefix		= 'S';
}
SaveCmd* SaveCmd_new(Game_Methods* gvptr){
	SaveCmd* this = (SaveCmd*)malloc(sizeof(SaveCmd));
	SaveCmd_init(this,gvptr);
	return this;
}


/**
 * Devolve uma nova instancia de Comando para ser carregado dinamicamente
 * */
Command* newInstance(Game_Methods* gvptr) {return (Command*) SaveCmd_new(gvptr);}
