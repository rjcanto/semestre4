#include "Command8.h"
/**
 * - Criação de Base de Dados com os Acronimos.
 * - Pesquisa pelo Semestre
 * */


char* Command8_filename="SemesterUniCurrbyAcronimo.cdb";
struct cdb_make Command8_cdbm;
int Command8_fd;
void Command8_createDB(){
	puts("======================================================================");
	puts("Criação de Base de Dados de Semestres");
	puts("======================================================================");
	Command8_fd = open(Command8_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command8_cdbm, Command8_fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}

/*	
Campo	Designação do Campo	Posição	Comprimento		Conteudo	OBS
 01		mec_number			   	01	2 bytes			Fixo
 02		Tamanho Nome			03	1 byte			Fixo		Indica o tamanho do texto referente ao Nome
 03		Nome					04  -----------		Variável	Comprimento dado pelo campo 02
 04		Tamanho email			--	1 byte			Variável	Indica o tamanho do texto referente ao Email
 05		Email					--	-----------		Variável	Comprimento dado pelo campo 04
*/
/**
 * Preenche os campos da estrutura com os valores necessários para alimentar a base de dados.
 * Uma vez que é alocado dinamicamente o valor que o campo 'line' irá ter, será necessário 
 * quem chamar esta função libertar o espaço alocao depois de não ser mais necessário. 
 * 
 * */
static void Command8_getLine(CDBLF * result,void* t ){
	char* cdb_line;
	int ret=0;
	UniCurr* this=(UniCurr*)t;
	if (this == NULL || result == NULL)  return;

	cdb_line=(char*)malloc(strlen(this->acronimo)+1+1);
	if (cdb_line == NULL) return;
	ret = sprintf(cdb_line,"%c%s",(this->acronimo != NULL)?(char)strlen(this->acronimo):0,\
									 (this->acronimo != NULL)?this->acronimo:"");
	result->size=ret;
	result->line=cdb_line;
}

void Command8_parseLine(char* line){
	char* key;
	unsigned short size;
	if (line == NULL || *line == 0)  return;
	size=*line;
	key = (char*)malloc(size+1) ;
	*(key + size)=0;
	strncpy(key,line+1,size);
	Command1_queryCDB1(NULL,key);/*<<<<<<<<<<<<<*/
	free(key);
}

void Command8_insert_CDB(void * this){
		Command_insert_CDB(this,&Command8_cdbm,&(((UniCurr*)this)->semestre),sizeof(char),&cdb_make_add,Command8_getLine);
}


void Command8_queryCDB1(char* key){
	char * str =(char*)malloc(2);
	char semestre =(1<<((char)(atoi(key))-1));
	*str=semestre;
	*(str+1)=0;
		Command_dbReader(Command8_filename,str,Command_dblist,Command8_parseLine);	
	free(str);
}

void Command8_destroyDB(){
    if (cdb_make_finish(&Command8_cdbm) == -1)
		puts("Command8_cdb_make_finish failed");
    close(Command8_fd);
	
}

