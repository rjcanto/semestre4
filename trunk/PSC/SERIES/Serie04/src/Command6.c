#include "Command6.h"
/**
 * - Criação de Base de Dados com as Dependencias
 * - Pesquisa pelo Acronimo, e devolve a descrição da UC de todas as Dep
 * 
 * */


char* Command6_filename="MecNbrUniCurrbyAcronimo.cdb";
struct cdb_make Command6_cdbm;
int Command6_fd;
void Command6_createDB(){
	puts("======================================================================");
	puts("Criação de Base de Dados de Docentes");
	puts("======================================================================");
	Command6_fd = open(Command6_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command6_cdbm, Command6_fd) < 0) {
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
void Command6_getLine(CDBLF * result,void* t ){
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

void Command6_parseLine(char* line){
	char* key;
	unsigned short size;
	if (line == NULL || *line == 0)  return;
	size=*line;
	key = (char*)malloc(size+1) ;
	
	*(key + size)=0;
	strncpy(key,line+1,size);
	Command1_queryCDB1(key);
	free(key);

}

void Command6_insert_CDB_by_MecNbr(void * this){
		char* key=(char*)malloc(3);
		unsigned short u=((UniCurr*)this)->mec_number;
		*(key+2)=0;
		unsignedShort2TwoBytes(key,u);
		Command6_insert_CDB(this,key,sizeof(((UniCurr*)this)->mec_number),&cdb_make_add,Command6_getLine);
		free (key);
}

void Command6_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF *,void* )){
	CDBLF cdb_line;
	getline(&cdb_line,this);
	
		fx( &Command6_cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}


void Command6_queryCDB1(char* key){
	unsigned short u;
	char *str=(char*)malloc(sizeof(unsigned short)+1);
	if (sscanf(key,"%hu",&u) == 0 )
			puts(">>Not a Number<<");
	*(str+2)=0;
	unsignedShort2TwoBytes(str,u);
	Command_dbReader(Command6_filename,str,Command_dblist,Command6_parseLine);	
	free(str);
}

void Command6_destroyDB(){
    if (cdb_make_finish(&Command6_cdbm) == -1)
		puts("Command6_cdb_make_finish failed");
    close(Command6_fd);
	
}

