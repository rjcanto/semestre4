#include "Common.h"
#include "Commands.h"

#define MAX_COMMANDS_READER 10 
static Command* myCommand[MAX_COMMANDS_READER];

static void mainCommands_init(){
	myCommand[0]=(Command*)Command2_ctor();
	myCommand[1]=(Command*)Command3_ctor();
	myCommand[2]=(Command*)Command1_ctor();
	myCommand[3]=(Command*)Command4_ctor();
	myCommand[4]=(Command*)Command5_ctor();
	myCommand[5]=(Command*)Command6_ctor();
	myCommand[6]=(Command*)Command7_ctor();
	myCommand[7]=(Command*)Command8_ctor();
	myCommand[8]=(Command*)Command9_ctor();
	myCommand[9]=(Command*)Command10_ctor();
}
static void mainCommands_clear(){
	int idx;
	for(idx=0;idx<MAX_COMMANDS_READER;++idx){
		if(myCommand[idx] != NULL)
			myCommand[idx]->vptr->dtor(myCommand[idx]);
	}
}
void sintaxe(char* program){
	int idx;
	mainCommands_init();
	fprintf(stderr,"Sintaxe:\n%s <option> <string>!\n",program);
	for (idx=0;idx<MAX_COMMANDS_READER;++idx){
		fprintf(stderr,"\t-%c :: %s\n",myCommand[idx]->vptr->opcao,myCommand[idx]->vptr->descricao);
	}
	mainCommands_clear();
}


int main(int argc,char** argv)
{
	if (argc != 3){
		fprintf(stderr,"Numero de Argumentos inválido!\n");
		sintaxe(argv[0]);
		exit(EXIT_FAILURE);
	}
	if (*argv[1] != '-'){
		fprintf(stderr,"Inicio de opção inválida!\n");
		sintaxe(argv[0]);		
		exit(EXIT_FAILURE);
	}
	if (*(argv[1]+1) > 'j' || *(argv[1]+1) < 'a'){
		fprintf(stderr,"Opção (%c) inválida!\n",*(argv[1]+1));
		sintaxe(argv[0]);		
		exit(EXIT_FAILURE);
	}else{
		unsigned char option= *(argv[1]+1) - 'a';
		mainCommands_init();
		myCommand[option]->vptr->execute(myCommand[option],argv[2]);
		mainCommands_clear();
	}
	
	return EXIT_SUCCESS;
}	
