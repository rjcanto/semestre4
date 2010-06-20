#include "Command1.h"

static const Command_Methods Command1_vtable = {
	(void (*)(void*)) Command1_dtor,
	(void (*)(void*)) Command1_createDB,
	(void (*)(void*)) Command1_destroyDB,
	(void (*)(void*,void*)) Command1_insert_CDB,
	(void (*)(char*)) Command1_parseLine,
	(void (*)(void*, char*) )Command1_queryCDB1,
	"Pesquisa pelo Acronino da UC, devolve a sua descrição.",
	'c'
};

void Command1_clear(Command1* this){
	this->filename=NULL;
	this->fd=0;
}

void Command1_dtor(Command1* this){
	if(this != NULL)
		Command1_clear(this);
	free(this);
}


void Command1_createDB(Command1* this){
	this->fd = open(this->filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&(this->cdbm), this->fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}

void Command1_parseLine(char* line){
	UniCurr* unidadeCurricular;
	char* idx=line;
	unsigned char a,b;
	if (line == NULL)  return;

	unidadeCurricular=UniCurr_emptyNew();
	a=*idx++;
	b=*idx++;
	unidadeCurricular->mec_number=(unsigned short)(a<<8)|b;;

	unidadeCurricular->type = (*idx != 0)?*(idx++):'Z';
	unidadeCurricular->semestre = (*idx != 0)?*(idx++):'Z';
	
	idx = CDB_field_equalize(&(unidadeCurricular->acronimo),idx);
	idx = CDB_field_equalize(&(unidadeCurricular->unidadeCurricular),idx);
	idx = CDB_field_equalize(&(unidadeCurricular->DependenciasFortes),idx);
	idx = CDB_field_equalize(&(unidadeCurricular->DependenciasFracas),idx);

	UniCurr_toString(unidadeCurricular);
	UniCurr_destroy(unidadeCurricular); 
}


static void Command1_getLine(CDBLF * result,void* t ){
	char* cdb_line;
	unsigned char a,b;
	int ret=0;
	UniCurr* this=(UniCurr*)t;
	if (this == NULL || result == NULL)  return;

	cdb_line=(char*)malloc((this->totalsize)+1);
	if (cdb_line == NULL) return;
	
	
	a= ((this->mec_number)>>8)&0x00FF;
	b= ( (this->mec_number)  )&0x00FF;

	ret = sprintf(cdb_line,"%c%c%c%c%c%s%c%s%c%s%c%s",a,b,this->type,this->semestre,\
									 (this->acronimo != NULL)?(char)strlen(this->acronimo):0,\
									 (this->acronimo != NULL)?this->acronimo:"",\
									 (this->unidadeCurricular != NULL)?(char)strlen(this->unidadeCurricular):0,\
									 (this->unidadeCurricular != NULL)?this->unidadeCurricular:"",\
									 (this->DependenciasFortes != NULL)?(char)strlen(this->DependenciasFortes):0,\
									 (this->DependenciasFortes != NULL)?this->DependenciasFortes:"",\
									 (this->DependenciasFracas != NULL)?(char)strlen(this->DependenciasFracas):0,\
									 (this->DependenciasFracas != NULL)?this->DependenciasFracas:""
	);
	result->size=ret;
	result->line=cdb_line;
}


void Command1_insert_CDB(Command1* this, void* t){
	Command_insert_CDB(t,&(this->cdbm),((UniCurr*)t)->acronimo,strlen(((UniCurr*)t)->acronimo),&cdb_make_add,Command1_getLine);
}

void Command1_queryCDB1(Command1* this,char* key){
	FILE* fp= fopen(this->filename, "rb");
	if (fp == NULL){
		fprintf(stderr, "Unable to open the file. Please check the file, or build de database again!\n");
		exit(2);	
	}
	fclose(fp);
	printf("Processing:%s\n",key);
	Command_dbReader(this->filename,key,Command_dblist,this->super.vptr->lineParser);	
}

void Command1_destroyDB(Command1* this){
    if (cdb_make_finish(&(this->cdbm)) == -1)
		puts("cdb_make_finish failed");
    close(this->fd);
}



Command1* Command1_ctor(){
	Command1* this=(Command1*)malloc(sizeof(Command1));
	Command1_init(this);
	return this;
}

void Command1_init(Command1* this){
	this->super.vptr =&Command1_vtable;
	this->filename = "UCbyAcronimo.cdb";	
}


