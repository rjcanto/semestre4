#include "Command2.h"

char* Command2_filename="UCbyAcronimo.cdb";
struct cdb_make Command2_cdbm;
int fd;

void Command2_createDB(){
	fd = open(Command2_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command2_cdbm, fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}


void Command2_getLine(CDBLF * result,UniCurr* this ){
	char* cdb_line;
	unsigned char a,b;
	int ret=0;
	
	if (this == NULL || result == NULL)  return;

	cdb_line=(char*)malloc((this->totalsize)+1); /*????*/
	if (cdb_line == NULL) return;
	a= ((this->mec_number)>>8)&0x00FF;
	b= (this->mec_number)&0x00FF;
	
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



void Command2_UniCurr_parseLine(char* line){
	UniCurr* unidadeCurricular;
	char* idx=line;
	char *str;

	if (line == NULL)  return;
	
	
	unidadeCurricular=UniCurr_emptyNew(); /*Alloc*/
	str=(char*)malloc(3);
	*str	  =*(idx++);
	*(str + 1)=*(idx++);
	*(str + 2)=0;
	unidadeCurricular->mec_number=twoByte2UnsignedShort(&str);
	free(str);

	/*obtido de acordo com a descrição dos campos do ficheiro*/
	/*Processa o Tipo*/
	unidadeCurricular->type = *(idx++);
	/*Processa o Semestre*/
	unidadeCurricular->semestre = *(idx++);
	
	/*Processa o Acronimo*/
	idx = CDB_field_equalize(&(unidadeCurricular->acronimo),idx);
	
	/*Processa a Unidade Curricular*/
	idx = CDB_field_equalize(&(unidadeCurricular->unidadeCurricular),idx);

	/*Processa as Dependencias Fortes*/
	idx = CDB_field_equalize(&(unidadeCurricular->DependenciasFortes),idx);

	/*Processa as Dependencias Fracas*/
	idx = CDB_field_equalize(&(unidadeCurricular->DependenciasFracas),idx);
	UniCurr_toString_debug(unidadeCurricular);
	UniCurr_destroy(unidadeCurricular); /*free*/
	
}




void Command2_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int)){
	CDBLF cdb_line;
	Command2_getLine(&cdb_line,(UniCurr*)this);

		fx( &Command2_cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}

void Command2_queryCDB1(){
	Command_dbReader(Command2_filename,"",Command_dblistAll,Command2_UniCurr_parseLine);	
}

void Command2_destroyDB(){
    if (cdb_make_finish(&Command2_cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);
	
}
