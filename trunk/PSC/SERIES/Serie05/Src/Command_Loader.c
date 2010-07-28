#include <assert.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Command_Loader.h"
#include "newtypes.h"
#include "Exception.h"



Cmds Commands_Array;
/**
 * Função que procede ao carregamento dinamico
 * */
static Command* Command_newInstance(const char* libName,Game_Methods* gvptr){
	void* hp;
	Command* (*newCommand)(Game_Methods*);
	Command* t;
	char tmp[50];
	
	if (sprintf(tmp,"./%sCmd.so",libName) == 0){return NULL;}
	
	hp = dlopen(tmp,RTLD_NOW);
	
	if (hp == NULL) {puts(dlerror());assert(0);return NULL;}
	
	*(void**)&newCommand = dlsym(hp,"newInstance");
			
	if(newCommand == NULL){dlclose(hp);return NULL;}
	t = newCommand(gvptr);
	t->handler =  hp;
	return t;
}
/**
 * Função para remover os caracteres de newline
 * */
static char * removeNL(char * str) {
	while( (*str != ' ') && (*str != '\r') && (*str != '\n') && (*str != 0) && (*str != EOF))str++;
		*str = 0;
	return str;
}
/**
 * Devolve um Array de nbr_commands comands
 * */
static Command** Commands_Array_new(int nbr_commands){
	Command** arr =  (Command**)calloc(nbr_commands,sizeof(Command*));
	assert (arr != NULL);
	return arr;
}
/**
 * Apaga o espaço alocado pelo array comands
 * */
static void Commands_Array_delete(Command** this){
	if (this == NULL) return;
	free(this);

}

/**
 * Descarrega a biblioteca
 * */
static void Command_unloading(Command* t){
	void* hp = t->handler;
	(t)->vptr->dtor(t);
	dlclose(hp);
}
/**
 * Descarrega as bibliotecas
 * */

void Command_unload(){
	int i;
	for (i=0;i< Commands_Array.length ; ++i){
		Command_unloading(Commands_Array.cmds[i]);
	}
	Commands_Array_delete(Commands_Array.cmds);
}
/**
 * Função que procede ao carregamento das Bibliotecas
 * */
boolean Command_load(Game_Methods* gvptr,char* cfgFile){
	int nLines;
	FILE* fin=NULL;
	char buffer[BUFFER];

	TRY {
		assert ((fin = fopen(cfgFile,"rb"))!= NULL);
		/*fseek(fin,0,SEEK_CUR);*/
		
		for (nLines=0 ; fgets(buffer,sizeof(buffer),fin) != NULL ; ++nLines) ;
		rewind(fin);
		Commands_Array.length=nLines;
		if (((Commands_Array.cmds) = Commands_Array_new(nLines)) == NULL){
		
			THROW(UNABLE_TO_READ_FILE_EXCEPTION);
			
		}else{
			int i;
			Command* com;
			for(i=0; i< nLines ; ++i){
				fgets(buffer,BUFFER,fin);
				removeNL(buffer);
				if ((com  = Command_newInstance(buffer,gvptr)) == NULL){
					THROW(UNABLE_TO_LOAD_LIBRARY_EXCEPTION) ;
				}
				(Commands_Array.cmds[i])=com;
			}
			
			fclose(fin);
		}
		
	}CATCH (UNABLE_TO_READ_FILE_EXCEPTION){
		printf("Error reading file %s.\n",cfgFile); 
		fclose(fin);
		return false;
	}CATCH (UNABLE_TO_LOAD_LIBRARY_EXCEPTION){
		printf("Error loading library %s.\n",buffer); 
		fclose(fin);
		return false;
	}TRY_END;
	system("clear");
	return true;		
}

/**
 * Função que executa uma função
 * */
void 	Command_execute(char* line){
	system("clear");
	if (line == NULL || *line == 0){ 
		return;
	}else{
		
		char prefix = toupper(*line);
		char* tmp;
		int i;
		tmp=removeNL(line);
		
		for(i=0 ; i< Commands_Array.length ; ++i){
			
			if ((Commands_Array.cmds[i])->vptr->prefix((Commands_Array.cmds[i])) == prefix) {
				(Commands_Array.cmds[i])->vptr->exec((Commands_Array.cmds[i]),line+1);
				return;
			}
	
		}
		printf("Invalid command %c\n",prefix);	
	}
	
}
