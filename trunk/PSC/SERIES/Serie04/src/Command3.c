#include "Command3.h"
/**
 * - Criação de Base de Dados com a Informação dos Docentes
 * - Pesquisa pelo Numero Mecanográfico do Docente
 * 
 * */

/*
char* Command3_filename="TeacherbyMecNbr.cdb";
struct cdb_make Command3_cdbm;
int fd;
*/


void Command3_clear(Command3* this){
	this->filename=NULL;
	this->fd=0;
}

void Command3_dtor(Command3* this){
	if(this != NULL)
		Command3_clear(this);
	free(this);
}


void Command3_createDB(Command3* this){
	puts("======================================================================");
	puts("Criação de Base de Dados da Unidade Curricular");
	puts("======================================================================");
	this->fd = open(this->filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&(this->cdbm), this->fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}

void Command3_parseLine(char* line){
	Teacher* professor;
	char* idx=line;
	unsigned char a,b;

	if (line == NULL)  return;

	professor=Teacher_new_empty(); /*Alloc*/

	a=*idx++;
	b=*idx++;
	professor->mec_number=(unsigned short)(a<<8)|b;

	/*obtido de acordo com a descrição dos campos do ficheiro*/
	/*Processa o Nome*/
	idx = CDB_field_equalize(&(professor->name),idx);
	
	/*Processa o Email*/
	idx = CDB_field_equalize(&(professor->email),idx);

	Teacher_toString(professor);
	Teacher_destroy(professor); /*free*/
	
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
static void Command3_getLine(CDBLF * result,void* t ){
	char* cdb_line;
	unsigned char a,b;
	int ret=0;
	Teacher* this = (Teacher*)t;
	if (this == NULL || result == NULL)  return;
	
	cdb_line=(char*)malloc((this->totalsize)+1);
	if (cdb_line == NULL) return;
	
	a= ((this->mec_number)>>8)&0x00FF;
	b= (this->mec_number)&0x00FF;
	
	ret=sprintf(cdb_line,"%c%c%c%s%c%s",a,b,\
							(this->name != NULL)?(char)strlen(this->name):0,\
							(this->name != NULL)?this->name:"",\
							(this->email != NULL)?(char)strlen(this->email):0,\
							(this->email != NULL)?this->email:""\
							);	
	result->size=ret;
	result->line=cdb_line;	
}

void Command3_insert_CDB(Command3* this,void* t){
		char* key=(char*)malloc(3);
		unsigned short u=((Teacher*)t)->mec_number;
		*(key+2)=0;
		unsignedShort2TwoBytes(key,u);
		Command_insert_CDB(t,&(this->cdbm),key,sizeof(((Teacher*)t)->mec_number),&cdb_make_add,Command3_getLine);
		free (key);
}

void Command3_queryCDB1(Command3* this,char* key){
	
	unsigned short u;
	char *str=(char*)malloc(sizeof(unsigned short)+1);
	if (sscanf(key,"%hu",&u) == 0 )
			puts(">>Not a Number<<");
	*(str+2)=0;
	unsignedShort2TwoBytes(str,u);
	Command_dbReader( this->filename,str,Command_dblist,this->super.vptr->lineParser);	
	free(str);
}

void Command3_destroyDB(Command3* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);
}

const Command_Methods Command3_vtable = {
	(void (*)(void*)) Command3_dtor,
	(void (*)(void*)) Command3_createDB,
	(void (*)(void*)) Command3_destroyDB,
	(void (*)(void*,void*)) Command3_insert_CDB,
	(void (*)(char*)) Command3_parseLine,
	(void (*)(void*, char*) )Command3_queryCDB1,
	"Criação de Base de Dados com a Informação dos Docentes. Pesquisa pelo Numero Mecanográfico do Docente",
	'b'
};


Command3* Command3_ctor(){
	Command3* this=(Command3*)malloc(sizeof(Command3));
	Command3_init(this);
	return this;
}

void Command3_init(Command3* this){
	(this->super).vptr = &Command3_vtable;
	this->filename = "TeacherbyMecNbr.cdb";	
}

