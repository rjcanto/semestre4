#include "Command5.h"
/**
 * - Criação de Base de Dados com as Dependencias
 * - Pesquisa pelo Acronimo, e devolve a descrição da UC de todas as Dep
 * 
 * */


char* Command5_filename="UCbyMecNbr.cdb";
struct cdb_make Command5_cdbm;
int Command5_fd;
void Command5_createDB(){
	puts("======================================================================");
	puts("Criação de Base de Dados de Docentes");
	puts("======================================================================");
	Command5_fd = open(Command5_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command5_cdbm, Command5_fd) < 0) {
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
static void Command5_getLine(CDBLF * result,void* t ){
	char* cdb_line;
	unsigned char a,b;
	int ret=0;
	UniCurr* this = (UniCurr*)t;
	if (this == NULL || result == NULL)  return;
	
	cdb_line=(char*)malloc(sizeof(this->mec_number)+1);
	if (cdb_line == NULL) return;
	
	a= ((this->mec_number)>>8)&0x00FF;
	b= (this->mec_number)&0x00FF;
	
	ret=sprintf(cdb_line,"%c%c",a,b);	
	result->size=ret;
	result->line=cdb_line;	
}

static void Command5_parseLine(char* line){
	char* key;
	unsigned short nbr;
	unsigned char a,b;
	if (line == NULL )  return;
	
	key = (char*)malloc(6) ;/*Numero de Caracteres que identificam maximo do short*/
	*(key + 5)=0;
	
	a=*line++;
	b=*line++;
	nbr=(unsigned short)(a<<8)|b;;
	
	if (sprintf(key,"%hu",nbr) == 0 )
	{
		puts("Not a Number");
	}	;
	Command3_queryCDB1(key);
	free(key);

}

void Command5_insert_CDB(void* this){
	Command_insert_CDB(this,&Command5_cdbm,((UniCurr*)this)->acronimo,strlen(((UniCurr*)this)->acronimo),&cdb_make_add,Command5_getLine);
}


void Command5_queryCDB1(char* key){
	Command_dbReader(Command5_filename,key,Command_dblist,Command5_parseLine);		
}

void Command5_destroyDB(){
    if (cdb_make_finish(&Command5_cdbm) == -1)
		puts("Command5_cdb_make_finish failed");
    close(Command5_fd);
	
}
