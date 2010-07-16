#include "LoadCmd.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
 * Executa o Comando
 * */
void  LoadCmd_exec(LoadCmd* this,char* txt){
    int size=0;
    char* loadGame=NULL;
    char* cur=NULL;
    FILE* fp=NULL;
    puts("Loading Game in MineSweeper.bin");
    if((fp=fopen("MineSweeper.bin","rb"))== NULL ) {puts("No game to Load!");return;}
    
    fread(&size,sizeof(char),1,fp);
    
    if (size){
		loadGame=(char*)calloc(size+2,sizeof(char));
		cur=loadGame;		
		fread(loadGame,sizeof(char),size+2,fp);
		for(;*cur;++cur)
			*cur = (*cur)+15;

		puts("Done.");	
		
	}else{
		puts("Error loading Game");	
		free(loadGame);
		loadGame=NULL;
	}
	
	fclose(fp);
	this->super.gvptr->load(loadGame);
}
/**
 * Mostra a ajuda para o comando
 * */
void  LoadCmd_help(LoadCmd* this){
	printf("[%c] - %s\n",this->prefix,this->description);
	puts(this->help);
}
/**
 * Devolve o prefixo do comando
 * */
char  LoadCmd_prefix(LoadCmd* this){return this->prefix;}

/**
 * Destrutores/Construtores e afins
 * */
void LoadCmd_cleanup(LoadCmd* this){
	if (this == NULL) return;
	free(this->help);
	free(this->description);
	Command_cleanup(&(this->super));
	this->prefix=0;
}
void LoadCmd_delete(LoadCmd* this){
	if (this == NULL) return;
	LoadCmd_cleanup(this);
	free(this);
}

const static Command_Methods loadcmd_vTable={
	(const void (*) (Command*)) 		LoadCmd_delete,
	(const char (*) (Command*))			LoadCmd_prefix,
	(const void (*) (Command*,char*))	LoadCmd_exec,
	(const void (*) (Command*))			LoadCmd_help,
	(const char*(*) (Command*))			Command_syntax
};


void LoadCmd_init(LoadCmd* this,Game_Methods* gvptr){
	Command_init(&(this->super),gvptr);
	this->super.vptr=&loadcmd_vTable;
	this->description = (char*)malloc(strlen("The Load Command!")+1);
	strcpy(this->description,"The Load Command!");
	
	this->help = (char*)malloc(strlen("Load the last point of the game.")+1);
	strcpy(this->help,"Load the last point of the game.");

	this->prefix		= 'L';
}
LoadCmd* LoadCmd_new(Game_Methods* gvptr){
	LoadCmd* this = (LoadCmd*)malloc(sizeof(LoadCmd));
	LoadCmd_init(this,gvptr);
	return this;
}


/**
 * Devolve uma nova instancia de Comando para ser carregado dinamicamente
 * */
Command* newInstance(Game_Methods* gvptr) {return (Command*) LoadCmd_new(gvptr);}
