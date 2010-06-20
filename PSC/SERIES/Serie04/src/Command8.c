#include "Command8.h"
void Command8_clear(Command8* this){
	this->filename=NULL;
	this->fd=0;
}

void Command8_dtor(Command8* this){
	if(this != NULL)
		Command8_clear(this);
	free(this);
}


void Command8_createDB(Command8* this){
	this->fd = open(this->filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&(this->cdbm), this->fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}
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

void Command8_insert_CDB(Command8* this,void* t){
		Command_insert_CDB(t,&(this->cdbm),&(((UniCurr*)t)->semestre),sizeof(char),&cdb_make_add,Command8_getLine);
}

void Command8_queryCDB1(Command8* this,char* key){
	FILE* fp= fopen(this->filename, "rb");

	char * str =(char*)malloc(2);
	char semestre =(1<<((char)(atoi(key))-1));
	*str=semestre;
	*(str+1)=0;
	if (fp == NULL){
		fprintf(stderr, "Unable to open the file. Please check the file, or build de database again!\n");
		free(str);
		exit(2);			
	}
	fclose(fp);
		printf("Processing:%s\n",key);
		Command_dbReader( this->filename,str,Command_dblist,this->super.vptr->lineParser);	
	free(str);
}

void Command8_destroyDB(Command8* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);	
}
static const Command_Methods Command8_vtable = {
	(void (*)(void*)) Command8_dtor,
	(void (*)(void*)) Command8_createDB,
	(void (*)(void*)) Command8_destroyDB,
	(void (*)(void*,void*)) Command8_insert_CDB,
	(void (*)(char*)) Command8_parseLine,
	(void (*)(void*, char*) )Command8_queryCDB1,
	"Pesquisa pelo Semestre. Devolve as Unidade Curriculares desse semestre.",
	'h'
};

Command8* Command8_ctor(){
	Command8* this=(Command8*)malloc(sizeof(Command8));
	Command8_init(this);
	return this;
}

void Command8_init(Command8* this){
	this->super.vptr = &Command8_vtable;
	this->filename = "SemesterUniCurrbyAcronimo.cdb";	
}
