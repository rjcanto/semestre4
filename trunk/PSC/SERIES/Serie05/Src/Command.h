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
#include "Minesweeper.h"
struct command;
typedef struct command Command;


typedef struct command_methods{
	const void		(*dtor)		(Command* this);
	const char 		(*prefix)	(Command* this);
	const void 		(*exec)		(Command*, char* line);
	const void 		(*help)		(Command* this);
	const char* 	(*syntax)	(Command* this);
}Command_Methods;

struct command{
	const Command_Methods* vptr;
	void* handler;
};

typedef struct cmds_array{
	Command** cmds;
	int length;
}Cmds;
	/*Métodos 'static' do java, que não precisam de objecto instanciado para serem chamado*/
	int Command_parseCol(char* txt);
	boolean Command_load(char* cfgFile);
	void Command_execute(char* line);
	int Command_parseLine(char* txt);



/*Variável Global que terá um array com os comandos	*/
extern Cmds Commands_Array;

	/*Comandos da Tabela de Metodos*/
	char 	Command_prefix(Command* this);
	char* 	Command_syntax(Command* this);
	void 	Command_exec(Command* this,char* line);
	void 	Command_help(Command* this);

	
	/*Métodos para inicialização e 'desinicialização' de variáveis*/
	void Command_init(Command* this);
	void Command_cleanup(Command* this);

	
#endif
