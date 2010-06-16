#include "Command6.h"
/**
 * - Criação de Base de Dados com os Acronimos
 * - Pesquisa pelo Numero Mecanografico do Docente Responsável.
 * 
 * */
void Command6_clear(Command6* this){
	this->filename=NULL;
	this->fd=0;
}

void Command6_dtor(Command6* this){
	if(this != NULL)
		Command6_clear(this);
	free(this);
}


void Command6_createDB(Command6* this){
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
static void Command6_getLine(CDBLF * result,void* t ){
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

void Command6_insert_CDB(Command6* this,void* t){
		char* key=(char*)malloc(3);
		unsigned short u=((UniCurr*)t)->mec_number;
		*(key+2)=0;
		unsignedShort2TwoBytes(key,u);
		Command_insert_CDB(t,&(this->cdbm),key,sizeof(((UniCurr*)t)->mec_number),&cdb_make_add,Command6_getLine);
		free (key);
}


void Command6_queryCDB1(Command6* this,char* key){
	unsigned short u;
	char *str=(char*)malloc(sizeof(unsigned short)+1);
	if (sscanf(key,"%hu",&u) == 0 )
			puts(">>Not a Number<<");
	*(str+2)=0;
	unsignedShort2TwoBytes(str,u);
	Command_dbReader(this->filename,str,Command_dblist,this->super.vptr->lineParser);	
	free(str);
}

void Command6_destroyDB(Command6* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);
}


const Command_Methods Command6_vtable = {
	(void (*)(void*)) Command6_dtor,
	(void (*)(void*)) Command6_createDB,
	(void (*)(void*)) Command6_destroyDB,
	(void (*)(void*,void*)) Command6_insert_CDB,
	(void (*)(char*)) Command6_parseLine,
	(void (*)(void*, char*) )Command6_queryCDB1,
	"Criação de Base de Dados com a Informação dos Docentes. Pesquisa pelo Numero Mecanográfico do Docente",
	'b'
};


Command6* Command6_ctor(){
	Command6* this=(Command6*)malloc(sizeof(Command6));
	Command6_init(this);
	return this;
}

void Command6_init(Command6* this){
	(this->super).vptr = &Command6_vtable;
	this->filename = "MecNbrUniCurrbyAcronimo.cdb";	
}

