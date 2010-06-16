#include "Command4.h"
/**
 * - Criação de Base de Dados com as Dependencias
 * - Pesquisa pelo Acronimo, e devolve a descrição da UC de todas as Dep
 * 
 * */

char* Command4_filename="UCDependenciasbyacronimo.cdb";
struct cdb_make Command4_cdbm;
int Command4_fd;
int UC_nbr=1;

void Command4_createDB(){
	puts("======================================================================");
	puts("Criação de Base de Dados de Acronimos e Dependencias");
	puts("======================================================================");
	Command4_fd = open(Command4_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command4_cdbm, Command4_fd) < 0) {
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
	int size;
	if(*line == 0){
		blank_print(UC_nbr);
		printf("|>%s: %s\n",text,"Sem Dependencias");
		return;
	}
	
	line++;
	size=strlen(line);
	while (size >0 && (field = get_next_field(line,delimiter)) != NULL ){
			blank_print(UC_nbr++);
			printf("|>%s: %s\n",text,field);
			/*blank_print(UC_nbr++);*/
			Command4_queryCDB1(field);
			
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

void Command4_insert_CDB(void * this){
		Command_insert_CDB(this,&Command4_cdbm,((UniCurr*)this)->acronimo,strlen(((UniCurr*)this)->acronimo),&cdb_make_add,Command4_getLine);
}




void Command4_queryCDB1(char* key){
	Command_dbReader(Command4_filename,key,Command_dblist,Command4_parseLine);		
}

void Command4_destroyDB(){
    if (cdb_make_finish(&Command4_cdbm) == -1)
		puts("Command4_cdb_make_finish failed");
    close(Command4_fd);
	
}
