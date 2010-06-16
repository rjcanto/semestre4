#include "Command7.h"
/**
 * - Criação de Base de Dados com os Acronimos
 * - Pesquisa pelo Tipo de cadeira
 * */
void Command7_clear(Command7* this){
	this->filename=NULL;
	this->fd=0;
}

void Command7_dtor(Command7* this){
	if(this != NULL)
		Command7_clear(this);
	free(this);
}


void Command7_createDB(Command7* this){
	puts("======================================================================");
	puts("Criação de Base de Dados de Acronimos e Dependencias");
	puts("======================================================================");
	this->fd = open(this->filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&(this->cdbm), this->fd) < 0) {
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
static void Command7_getLine(CDBLF * result,void* t ){
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

void Command7_parseLine(char* line){
	char* key;
	unsigned short size;
	Command1* c1;
	if (line == NULL || *line == 0)  return;
	c1=Command1_ctor();
	
	size=*line;
	key = (char*)malloc(size+1) ;
	
	*(key + size)=0;
	strncpy(key,line+1,size);
	c1->super.vptr->queryDB(c1,key);
	c1->super.vptr->dtor(c1);
	free(key);

}

void Command7_insert_CDB(Command7* this,void* t){
		Command_insert_CDB(t,&(this->cdbm),&(((UniCurr*)t)->type),sizeof(char),&cdb_make_add,Command7_getLine);
}

void Command7_queryCDB1(Command7* this,char* key){
	Command_dbReader( this->filename,key,Command_dblist,this->super.vptr->lineParser);	
}

void Command7_destroyDB(Command7* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);
}


const Command_Methods Command7_vtable = {
	(void (*)(void*)) Command7_dtor,
	(void (*)(void*)) Command7_createDB,
	(void (*)(void*)) Command7_destroyDB,
	(void (*)(void*,void*)) Command7_insert_CDB,
	(void (*)(char*)) Command7_parseLine,
	(void (*)(void*, char*) )Command7_queryCDB1,
	"Criação de Base de Dados com a Informação dos Docentes. Pesquisa pelo Numero Mecanográfico do Docente",
	'b'
};


Command7* Command7_ctor(){
	Command7* this=(Command7*)malloc(sizeof(Command7));
	Command7_init(this);
	return this;
}

void Command7_init(Command7* this){
	(this->super).vptr = &Command7_vtable;
	this->filename = "TypeUniCurrbyAcronimo.cdb";	
}



