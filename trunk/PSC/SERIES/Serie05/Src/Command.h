#ifndef COMMAND_H
#define COMMAND_H
#define BUFFER 1024
#include "CommandInterface.h"
#include "GameInterface.h"
	/*Comandos da Tabela de Metodos*/
	char 	Command_prefix(Command* this);
	char* 	Command_syntax(Command* this);
	void 	Command_exec(Command* this,char* line);
	void 	Command_help(Command* this);

	
	/*Métodos para inicialização e 'desinicialização' de variáveis*/
	void Command_init(Command* this,Game_Methods* gvptr);
	void Command_cleanup(Command* this);
	int Command_parseCol(char* txt);
	int Command_parseLine(char* txt);
	extern Cmds Commands_Array;
#endif
