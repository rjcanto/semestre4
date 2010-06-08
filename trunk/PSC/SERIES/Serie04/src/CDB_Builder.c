#include "CDB_Builder.h"

/* compilar com opção -lcdb */


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
void CDB_insert_Teacher (Teacher* this, struct cdb_make* cdbm, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int)){
	CDBLF cdb_line;
	CDB_Teacher_getLine(&cdb_line,this);
	
		fx(cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}
unsigned short twoByte2UnsignedShort(char** twobyte){
	unsigned char a;
	unsigned char b;
	a=**twobyte++;
	b=**twobyte++;
	return(unsigned short)(a<<8)|b;
}

void unsignedShort2TwoBytes(char** dest, const unsigned short ush){
	unsigned char a,b;
	a= (ush>>8)&0x00FF;
	b= ( ush  )&0x00FF;
	**dest = a;
	**(dest+1)=b;
}


void CDB_Teacher_getLine(CDBLF * result, Teacher* this){
	char* cdb_line;
	unsigned char a,b;
	int ret=0;
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
	Teacher_toString_debug(this);
}
void CDB_Teacher_parseLine(char* line){
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
 02		type				   	03	1 byte			Fixo
 03		semestre				04	1 byte			Fixo
 04		Tamanho Acronimo		05	1 byte			Fixo		Indica o tamanho do texto referente ao Acronimo
 05		Acronimo				06  -----------		Variável	Comprimento dado pelo campo 04
 06		Tamanho Uni Curr		--	1 byte			Variável	Indica o tamanho do texto referente à Unidade Curricular
 07		Unidade Curricular		--	-----------		Variável	Comprimento dado pelo campo 06
 08		Tamanho Dep Fortes		--	1 byte			Variável	Indica o tamanho do texto referente à Dep Fortes
 09		Dependencia Fortes		--	-----------		Variável	Comprimento dado pelo campo 08
 10		Tamanho Dep Fracas		--	1 byte			Variável	Indica o tamanho do texto referente à Dep Fracas
 11		Dependencia Fracas		--	-----------		Variável	Comprimento dado pelo campo 10
*/

/**
 * Preenche os campos da estrutura com os valores necessários para alimentar a base de dados.
 * Uma vez que é alocado dinamicamente o valor que o campo 'line' irá ter, será necessário 
 * quem chamar esta função libertar o espaço alocao depois de não ser mais necessário. 
 * 
 * */
void CDB_UniCurr_getLine(CDBLF * result,UniCurr* this ){
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
byte* CDB_field_equalize(char**  field, char * idx){
	if (*idx != 0){
		*field = strndup(idx+1,*idx);
		idx = idx + 1 + *idx;
	}else{
		*field=NULL;
		++idx;
	}
	return idx;
}

void CDB_UniCurr_parseLine(char* line){
	UniCurr* unidadeCurricular;
	char* idx=line;
	char* str;

	if (line == NULL)  return;
	str=strndup(idx,3);
	unidadeCurricular=UniCurr_emptyNew(); /*Alloc*/
	
	str[0]=*idx++;
	str[1]=*idx++;
	str[2]=0;
	unidadeCurricular->mec_number=twoByte2UnsignedShort(&str);
	
	
	/*unidadeCurricular->mec_number=(unsigned short)(a<<8)|b;*/

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

	UniCurr_toString(unidadeCurricular);
	UniCurr_destroy(unidadeCurricular); /*free*/
	
}

void CDB_insert_Unicurr ( UniCurr * this, struct cdb_make* cdbm, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int)){
	CDBLF cdb_line;
	CDB_UniCurr_getLine(&cdb_line,this);

		fx(cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}
