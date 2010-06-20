#include "Command7.h"
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
	this->fd = open(this->filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&(this->cdbm), this->fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}
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
	c1->super.vptr->execute(c1,key);
	c1->super.vptr->dtor(c1);
	free(key);

}

void Command7_insert_CDB(Command7* this,void* t){
		Command_insert_CDB(t,&(this->cdbm),&(((UniCurr*)t)->type),sizeof(char),&cdb_make_add,Command7_getLine);
}

void Command7_queryCDB1(Command7* this,char* key){
	FILE* fp= fopen(this->filename, "rb");
	if (fp == NULL){
		fprintf(stderr, "Unable to open the file. Please check the file, or build de database again!\n");
		exit(2);	
	}
	fclose(fp);
	printf("Processing:%s\n",key);
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
	"Pesquisa pelo Tipo de Unidade Curricular (B- Obrigatória, C- Complementar, P- Optativa).",
	'g'
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



