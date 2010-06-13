#include "Command1.h"
/**
 * - Criação de Base de Dados com a Informação das Unidade Curriculares
 * - Pesquisa pela Acronino da UC
 * 
 * */
char* Command1_filename="UCbyAcronimo.cdb";
struct cdb_make Command1_cdbm;
int fd;

void Command1_createDB(){
	puts("======================================================================");
	puts("Criação de Base de Dados da Unidade Curricular");
	puts("======================================================================");
	fd = open(Command1_filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&Command1_cdbm, fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}

void Command1_UniCurr_parseLine(char* line){
	UniCurr* unidadeCurricular;
	char* idx=line;
	char *str;

	if (line == NULL)  return;
	
	unidadeCurricular=UniCurr_emptyNew();
	str=(char*)malloc(3);
	*str	  =*(idx++);
	*(str + 1)=*(idx++);
	*(str + 2)=0;
	unidadeCurricular->mec_number=twoByte2UnsignedShort(&str);
	free(str);

	unidadeCurricular->type = *(idx++);
	unidadeCurricular->semestre = *(idx++);
	idx = CDB_field_equalize(&(unidadeCurricular->acronimo),idx);
	idx = CDB_field_equalize(&(unidadeCurricular->unidadeCurricular),idx);
	idx = CDB_field_equalize(&(unidadeCurricular->DependenciasFortes),idx);
	idx = CDB_field_equalize(&(unidadeCurricular->DependenciasFracas),idx);
	/*Aqui apresenta o resultado*/
	/*UniCurr_toString(unidadeCurricular);*/
	UniCurr_destroy(unidadeCurricular); 
}


void Command1_getLine(CDBLF * result,void* t ){
	char* cdb_line;
	char* str;
	/*unsigned char a,b;*/
	int ret=0;
	UniCurr* this=(UniCurr*)t;
	if (this == NULL || result == NULL)  return;

	cdb_line=(char*)malloc((this->totalsize)+1);
	if (cdb_line == NULL) return;
	str=(char*)malloc(sizeof(this->mec_number)+1);
	*(str+2)=0;
	unsignedShort2TwoBytes(str,this->mec_number);

	ret = sprintf(cdb_line,"%s%c%c%c%s%c%s%c%s%c%s",str,this->type,this->semestre,\
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
	free(str);
}


void Command1_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF*, void* )){
	CDBLF cdb_line;
	getline(&cdb_line,this);

		fx( &Command1_cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}
void Command1_queryCDB1(char* key){
	Command_dbReader(Command1_filename,key,Command_dblist,Command1_UniCurr_parseLine);	
}

void Command1_destroyDB(){
    if (cdb_make_finish(&Command1_cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);
	
}
