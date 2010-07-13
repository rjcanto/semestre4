#ifndef COMMANDLOADER_H
#define COMMANDLOADER_H
#define BUFFER 1024

#include "CommandInterface.h"
#include "GameInterface.h"


	/*Métodos 'static' do java, que não precisam de objecto instanciado para serem chamado*/
	boolean Command_load(Game_Methods* gvptr,char* cfgFile);
	void Command_unload();
	void Command_execute(char* line);
	Cmds Commands_Array;
#endif
