#ifndef COMMAND_H
#define COMMAND_H
#include "newtypes.h"
#include "Exception.h"
#include <assert.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "CommandInterface.h"
#include "GameInterface.h"
#define BUFFER 1024

struct command{
	const Command_Methods* 	vptr;
	const Game_Methods*	gvptr;
	void* handler;
};

typedef struct cmds_array{
	Command** cmds;
	int length;
}Cmds;
	/*Métodos 'static' do java, que não precisam de objecto instanciado para serem chamado*/
	int Command_parseCol(char* txt);
	boolean Command_load(Game_Methods* gvptr,char* cfgFile);
	void Command_unload();
	void Command_execute(char* line);
	int Command_parseLine(char* txt);



	/*Comandos da Tabela de Metodos*/
	char 	Command_prefix(Command* this);
	char* 	Command_syntax(Command* this);
	void 	Command_exec(Command* this,char* line);
	void 	Command_help(Command* this);

	
	/*Métodos para inicialização e 'desinicialização' de variáveis*/
	void Command_init(Command* this,Game_Methods* gvptr);
	void Command_cleanup(Command* this);

	
#endif
