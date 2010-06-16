#include "Command4.h"
/**
 * - Criação de Base de Dados com as Dependencias
 * - Pesquisa pelo Acronimo, e devolve a descrição da UC de todas as Dep
 * 
 * */


void Command4_clear(Command4* this){
	this->filename=NULL;
	this->fd=0;
}

void Command4_dtor(Command4* this){
	if(this != NULL)
		Command4_clear(this);
	free(this);
}

static int UC_nbr=1;

void Command4_createDB(Command4* this){
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
static void Command4_getLine(CDBLF * result,void* t ){
	char* cdb_line;
	int ret=0;
	unsigned char size;
	UniCurr* this=(UniCurr*)t;
	if (this == NULL || result == NULL)  return;
	
	size=((this->DependenciasFortes != NULL)?(char)strlen(this->DependenciasFortes)+1:1)  +  ((this->DependenciasFracas != NULL)?(char)strlen(this->DependenciasFracas)+1:1) ;

	cdb_line=(char*)malloc(size+2);
	if (cdb_line == NULL) return;
	
	ret = sprintf(cdb_line,"%c%s%c%s%c",\
							(this->DependenciasFortes != NULL)?(char)strlen(this->DependenciasFortes):0,\
							(this->DependenciasFortes != NULL)?this->DependenciasFortes:"",\
							(this->DependenciasFracas != NULL)?(char)strlen(this->DependenciasFracas):0,\
							(this->DependenciasFracas != NULL)?this->DependenciasFracas:"",0\
							);
	result->size=ret;
	result->line=cdb_line;
}
static void blank_print(int nbr){
		while(nbr-- > 0)
			printf("---");
}
static void Command4_parseDependencias (const char * line, char delimiter, char*  text){
	char * field;
	Command4* c4;
	int size;
	if(*line == 0){
		blank_print(UC_nbr);
		printf("|>%s: %s\n",text,"Sem Dependencias");
		return;
	}
	c4=Command4_ctor();
	line++;
	size=strlen(line);
	while (size >0 && (field = get_next_field(line,delimiter)) != NULL ){
			blank_print(UC_nbr++);
			printf("|>%s: %s\n",text,field);
			/*blank_print(UC_nbr++);*/
			/*Command4_queryCDB1(field);*/
			c4->super.vptr->queryDB(c4, field);
			UC_nbr-=1;
			/*Command1_queryCDB1(field);*/
			line=line + strlen(field)+1;
			size-=strlen(field)+1;
			free(field);
			field=NULL;
		}
		if (field != NULL){
			free(field);
			field=NULL;	
		}
		c4->super.vptr->dtor(c4);
}

void Command4_parseLine(char* line){
	char delimiter=';';
	char *newline;
	unsigned short size=0;
	if (line == NULL )  return;

	/*Parse Dependencias Fortes*/
	size = *line;
	if ((newline=strndup(line,size+1)) == NULL)
		return;

	Command4_parseDependencias(newline,delimiter,"Dependencias Fortes");
	free(newline);
		/*Parse Dependencias Fracas*/
	line = line + size +1;
	size = *(line);
	if ((newline=strndup(line,size+1)) == NULL)
		return;

	Command4_parseDependencias(newline,delimiter,"Dependencias Fracas");
	free(newline);
}

void Command4_insert_CDB(Command4* this,void* t){
		Command_insert_CDB(t,&(this->cdbm),((UniCurr*)t)->acronimo,strlen(((UniCurr*)t)->acronimo),&cdb_make_add,Command4_getLine);
}




void Command4_queryCDB1(Command4* this,char* key){
	Command_dbReader( this->filename,key,Command_dblist,this->super.vptr->lineParser);	
}

void Command4_destroyDB(Command4* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);
}
const Command_Methods Command4_vtable = {
	(void (*)(void*)) Command4_dtor,
	(void (*)(void*)) Command4_createDB,
	(void (*)(void*)) Command4_destroyDB,
	(void (*)(void*,void*)) Command4_insert_CDB,
	(void (*)(char*)) Command4_parseLine,
	(void (*)(void*, char*) )Command4_queryCDB1,
	"Criação de Base de Dados com a Informação dos Docentes. Pesquisa pelo Numero Mecanográfico do Docente",
	'b'
};


Command4* Command4_ctor(){
	Command4* this=(Command4*)malloc(sizeof(Command4));
	Command4_init(this);
	return this;
}

void Command4_init(Command4* this){
	(this->super).vptr = &Command4_vtable;
	this->filename = "UCDependenciasbyacronimo.cdb";	
}

