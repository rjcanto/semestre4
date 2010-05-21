/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/
#include "LinkedList.c"
#define MAX_BUFFER 100
void lineProcessor(char * line);
void fileProcessor(char* filename, LinkedList * list){
	FILE* f = fopen(filename, "rb");
	char string[MAX_BUFFER];

	assert(f != NULL);
	
	while (fgets(string,MAX_BUFFER,f) != NULL){
		lineProcessor(string);
	}
	
	
	fclose(f);
}
