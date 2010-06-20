#include "Command5.h"
void Command5_clear(Command5* this){
	this->filename=NULL;
	this->fd=0;
}

void Command5_dtor(Command5* this){
	if(this != NULL)
		Command5_clear(this);
	free(this);
}


void Command5_createDB(Command5* this){
	this->fd = open(this->filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&(this->cdbm), this->fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}
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

void Command5_parseLine(char* line){
	char* key;
	unsigned short nbr;
	unsigned char a,b;
	Command3* c3;
	if (line == NULL )  return;
	c3=Command3_ctor();
	key = (char*)malloc(6) ;/*Numero de Caracteres que identificam maximo do short*/
	*(key + 5)=0;
	
	a=*line++;
	b=*line++;
	nbr=(unsigned short)(a<<8)|b;;
	
	if (sprintf(key,"%hu",nbr) == 0 )
	{
		puts("Not a Number");
	}	;
	c3->super.vptr->execute(c3,key);
	c3->super.vptr->dtor(c3);
	free(key);

}

void Command5_insert_CDB(Command5* this,void* t){
		Command_insert_CDB(t,&(this->cdbm),((UniCurr*)t)->acronimo,strlen(((UniCurr*)t)->acronimo),&cdb_make_add,Command5_getLine);
}
void Command5_queryCDB1(Command5* this,char* key){
	FILE* fp= fopen(this->filename, "rb");
	if (fp == NULL){
		fprintf(stderr, "Unable to open the file. Please check the file, or build de database again!\n");
		exit(2);	
	}
	fclose(fp);
	printf("Processing:%s\n",key);
	Command_dbReader( this->filename,key,Command_dblist,this->super.vptr->lineParser);	
}

void Command5_destroyDB(Command5* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);
}
static const Command_Methods Command5_vtable = {
	(void (*)(void*)) Command5_dtor,
	(void (*)(void*)) Command5_createDB,
	(void (*)(void*)) Command5_destroyDB,
	(void (*)(void*,void*)) Command5_insert_CDB,
	(void (*)(char*)) Command5_parseLine,
	(void (*)(void*, char*) )Command5_queryCDB1,
	"Pesquisa pelo Acronimo, devolve o Numero Mecanografico do Docente Responsável.",
	'e'
};


Command5* Command5_ctor(){
	Command5* this=(Command5*)malloc(sizeof(Command5));
	Command5_init(this);
	return this;
}

void Command5_init(Command5* this){
	(this->super).vptr = &Command5_vtable;
	this->filename = "UniCurrbyMecNbr.cdb";	
}

