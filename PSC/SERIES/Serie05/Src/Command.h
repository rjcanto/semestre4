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
#define BUFFER 1024


struct command;
typedef struct command Command;

typedef struct command_methods{
	const void		(*dtor)		(Command* this);
	const char 		(*prefix)	();
	const void 		(*exec)		(char* line);
	const void 		(*help)		();
	const char* 	(*syntax)	();
}Command_Methods;

struct command{
	const Command_Methods* vptr;
	void* handler;
};

typedef struct cmds_array{
	Command* cmds;
	int length;
}Cmds;
/*Variável Global que terá um array com os comandos	*/
extern  Cmds Commands_Array;

	/*Comandos da Tabela de Metodos*/
	char 	Command_prefix();
	char* 	Command_syntax();
	void 	Command_exec(char* line);
	void 	Command_help();

	/*Métodos 'static' do java, que não precisam de objecto instanciado para serem chamado*/
	boolean Command_load(char* cfgFile);
	void 	Command_execute(char* line);
	const int Command_parseLine(char* txt);
	const int Command_parseCol(char* txt);
	
	/*Métodos para inicialização e 'desinicialização' de variáveis*/
	void Command_init(Command* this);
	void Command_cleanup(Command* this);

	
#endif
