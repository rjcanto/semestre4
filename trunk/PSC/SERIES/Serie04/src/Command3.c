#include "Command3.h"
/**
 * - Criação de Base de Dados com a Informação dos Docentes
 * - Pesquisa pelo Numero Mecanográfico do Docente
 * 
 * */


char* Command3_filename="TeacherbyMecNbr.cdb";
struct cdb_make Command3_cdbm;
int fd;

void Command3_createDB(){
	puts("======================================================================");
	puts("Criação de Base de Dados de Docentes");
	puts("======================================================================");
	fd = open(Command3_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command3_cdbm, fd) < 0) {
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

void Command3_insert_CDB(void * this){
		char* key=(char*)malloc(3);
		unsigned short u=((Teacher*)this)->mec_number;
		*(key+2)=0;
		unsignedShort2TwoBytes(key,u);
		Command_insert_CDB(this,&Command3_cdbm,key,sizeof(((Teacher*)this)->mec_number),&cdb_make_add,Command3_getLine);
		free (key);
}

void Command3_queryCDB1(char* key){
	unsigned short u;
	char *str=(char*)malloc(sizeof(unsigned short)+1);
	if (sscanf(key,"%hu",&u) == 0 )
			puts(">>Not a Number<<");
	
	*(str+2)=0;
	unsignedShort2TwoBytes(str,u);
	Command_dbReader(Command3_filename,str,Command_dblist,Command3_parseLine);	
	free(str);
}

void Command3_destroyDB(){
    if (cdb_make_finish(&Command3_cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);
	
}
