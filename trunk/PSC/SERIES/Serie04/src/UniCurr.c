#include "UniCurr.h"
#include "Teacher.h"

/**
 * 	Conditional jump or move depends on uninitialised value(s)
 */ 
UniCurr* UniCurr_new(char* unidadeCurricular,char* acronimo, char* depFortes,char* depFracas, unsigned short mec_number,	byte type, byte semestre)
{
	UniCurr* this = (UniCurr*)malloc(sizeof(UniCurr));
	UniCurr_init(this,unidadeCurricular, acronimo, depFortes, depFracas, mec_number, type, semestre);
	return this;						
}

int UniCurr_assign_Value(char * key, char* value){
	if (value == NULL){
		key=NULL;

		puts("NULL>>");
		return 1;
	}else{
		key = value;
		puts(value);
		return strlen(value)+1;
	}	
}

UniCurr* UniCurr_new_fromString(char* line, char delimiter){
	UniCurr* this=(UniCurr*)malloc(sizeof(UniCurr));
	int size=0;
	int tmpidx=0;
	int idx=0;
	char* tmp=line;

	/*Processa o Acronimo*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->acronimo=NULL;
		idx+=1;
		free(tmp);
	}else{
		tmpidx=strlen(tmp)+1;
		this->acronimo=tmp;
		
		idx+=tmpidx;
		size+=tmpidx;
	}
	
	/*Processa o Tipo*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->type=0;
		idx+=1;
	}else{
		tmpidx=strlen(tmp)+1;
		this->type=*tmp;

		idx+=tmpidx;
		size+=sizeof(this->type);
	}
	free(tmp);
	/*Processa o Semestre*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->semestre=0;
		idx+=1;
	}else{
		tmpidx=strlen(tmp)+1;
		this->semestre=*tmp;
		
		idx+=tmpidx;
		size+=sizeof(this->semestre);
	}
	free(tmp);
	/*Processa as DepFortes*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->DependenciasFortes=NULL;
		idx+=1;
		free(tmp);		
	}else{
		this->DependenciasFortes=tmp;
		tmpidx=strlen(tmp)+1;
		idx+=tmpidx;
		size+=tmpidx;
	}

	/*Processa as DepFracas*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->DependenciasFracas=NULL;
		idx+=1;
		free(tmp);		
	}else{
		this->DependenciasFracas=tmp;
		tmpidx=strlen(tmp)+1;
		idx+=tmpidx;
		size+=tmpidx;
	}

	/*Processa o Nome da Cadeira*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->unidadeCurricular=NULL;
		idx+=1;
		free(tmp);		
	}else{
		tmpidx=strlen(tmp)+1;
		this->unidadeCurricular=tmp;

		idx+=tmpidx;
		size+=tmpidx;

	}

	/*Processa o numero de Docente*/
	tmp=get_next_field(line+idx,delimiter);
	
	
	if (tmp == NULL){
		this->mec_number=0;
	}else{
		if ( sscanf(tmp, "%hu", &(this->mec_number)) == 0 )
		{
			puts("Not a Number");
			this->mec_number =0;
		}
	}
	size+=sizeof(this->mec_number);
	this->totalsize=size;
	free(tmp);
	
	return this;
}

					
void UniCurr_init(	UniCurr* this, char* unidadeCurricular,	char* acronimo, char* depFortes, char* depFracas, unsigned short mec_number, byte type, byte semestre){
	int size=0;
	int tmpidx=0;

	if (unidadeCurricular != NULL){
		char* uc;
		tmpidx=strlen(unidadeCurricular)+1;
		size+=tmpidx;

		uc=(char*)malloc(tmpidx);
		strcpy(uc,unidadeCurricular);
		this->unidadeCurricular=uc;		
	}else{ this->unidadeCurricular = NULL;}
	
	if (acronimo != NULL){
		char* ac;
		tmpidx=strlen(acronimo)+1;
		size+=tmpidx;

		ac=(char*)malloc(tmpidx);
		strcpy(ac,acronimo);
		this->acronimo=ac;
	}else{this->acronimo = NULL;}
	
	if (depFortes != NULL){
		char* dF;
		tmpidx=strlen(depFortes)+1;
		size+=tmpidx;
		
		dF=(char*)malloc(tmpidx);
		strcpy(dF,depFortes);
		this->DependenciasFortes = dF;		
	}else{ depFortes = NULL;}
	
	if (depFracas != NULL){
		char* df;
		tmpidx=strlen(depFracas)+1;
		size+=tmpidx;
		
		df=(char*)malloc(tmpidx);
		strcpy(df,depFracas);
		this->DependenciasFracas = df;			
	}else{this->DependenciasFracas = NULL;}
	
	this->mec_number=mec_number;
	size+=sizeof(this->mec_number);
	
	this->type =type;
	size+=sizeof(this->type);
	
	this->semestre =semestre;					
	size+=sizeof(this->semestre);
	
	this->totalsize=size;
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
void UniCurr_line2CDB1(UniCurr* this){
	printf("%hu%c%c%c%s%c%s%c%s%c%s\n",this->mec_number,\
									 this->type,\
									 this->semestre,\
									 (this->acronimo != NULL)?(char)strlen(this->acronimo):0,\
									 (this->acronimo != NULL)?this->acronimo:"",\
									 (this->unidadeCurricular != NULL)?(char)strlen(this->unidadeCurricular):0,\
									 (this->unidadeCurricular != NULL)?this->unidadeCurricular:"",\
									 (this->DependenciasFortes != NULL)?(char)strlen(this->DependenciasFortes):0,\
									 (this->DependenciasFortes != NULL)?this->DependenciasFortes:"",\
									 (this->DependenciasFracas != NULL)?(char)strlen(this->DependenciasFracas):0,\
									 (this->DependenciasFracas != NULL)?this->DependenciasFracas:""
									 
	);

}

void UniCurr_line2CDB(UniCurr* this){
	char* cdb_line=(char*)malloc((this->totalsize)+2);
	int ret;
	
	ret = sprintf(cdb_line,"%hu%c%c%c%s%c%s%c%s%c%s",this->mec_number,this->type,this->semestre,\
									 (this->acronimo != NULL)?(char)strlen(this->acronimo):0,\
									 (this->acronimo != NULL)?this->acronimo:"",\
									 (this->unidadeCurricular != NULL)?(char)strlen(this->unidadeCurricular):0,\
									 (this->unidadeCurricular != NULL)?this->unidadeCurricular:"",\
									 (this->DependenciasFortes != NULL)?(char)strlen(this->DependenciasFortes):0,\
									 (this->DependenciasFortes != NULL)?this->DependenciasFortes:"",\
									 (this->DependenciasFracas != NULL)?(char)strlen(this->DependenciasFracas):0,\
									 (this->DependenciasFracas != NULL)?this->DependenciasFracas:""
	);								 
	printf(">>>>>>>> %u >> %u\n",this->totalsize, ret );
	puts(cdb_line);
	
	if (cdb_line != NULL)
		free(cdb_line);
	cdb_line=NULL;
}


void UniCurr_toString2(UniCurr* this){
	printf("Acronimo: %s\tNome: %s\n",this->acronimo,this->unidadeCurricular);
	printf("\tDependencias Fortes: %s\n\tDependencias Fracas: %s\n",this->DependenciasFortes,this->DependenciasFracas);
	printf("\tTipo: %c\tSemestre: %d\n",this->type,this->semestre);
	printf("\tDocente Responsável: %hu\n",this->mec_number);
	printf("\ttotal size: %hu byes\n",this->totalsize);
}

void UniCurr_toString(UniCurr* this){
	printf("Acronimo: %s (%u)\tNome: %s (%u)\n",this->acronimo,strlen(this->acronimo)+1,this->unidadeCurricular,strlen(this->unidadeCurricular)+1);
	printf("\tDependencias Fortes: %s (%u)\n\tDependencias Fracas: %s (%u)\n",this->DependenciasFortes,(this->DependenciasFortes!= NULL)?strlen(this->DependenciasFortes)+1:0,this->DependenciasFracas,(this->DependenciasFracas!= NULL)?strlen(this->DependenciasFracas)+1:0);
	printf("\tTipo: %c (%u)\tSemestre: %d(%u)\n",this->type,sizeof(this->type),this->semestre,sizeof(this->semestre));
	printf("\tDocente Responsável: %hu (%u)\n",this->mec_number,sizeof(this->mec_number));
	printf("\ttotal size: %hu byes\n",this->totalsize);
}
void UniCurr_cleanup(UniCurr* this){
	if (this == NULL) return;
	
	if (this->unidadeCurricular != NULL){
		free(this->unidadeCurricular);
		this->unidadeCurricular=NULL;
	}
	if (this->acronimo != NULL){
		free(this->acronimo);
		this->acronimo=NULL;
	}
	if (this->DependenciasFortes != NULL){
		free(this->DependenciasFortes);
		this->DependenciasFortes=NULL;
	}
	if (this->DependenciasFracas != NULL){
		free(this->DependenciasFracas);
		this->DependenciasFracas=NULL;
	}	
}

void UniCurr_destroyer(UniCurr* this){
	if (this == NULL) return;
	UniCurr_cleanup(this);
	free(this);	
}


int main()
{
	 UniCurr * t1 = t1;
	 UniCurr * t2 = t2;
	 UniCurr * t3 = t3;
	 UniCurr * t4 = t4;
	 UniCurr * t5 = t5;
	 Teacher * tt1 = 0;
	 Teacher * tt2 = 0;

	 char string1[]="PDSI|P|32|Com||Processamento Digital de Sinal e Imagem|690";
	 char string2[]="LIC|B|2|Pg;LSD||Laboratório de Informática e Computadores|564";
	 char string3[]="AVE|B|8||PSC;AED|Ambientes Virtuais de Execução|697";
	 char string4[]="LS|B|8|POO;SI1|PSC;AED|Laboratório de Software|889";
	 char string5[]="819|Acilina Nascimento Caneco|d819@deetc.isel.pt";

	 
	 
	t1 = UniCurr_new("EICARAMBA","EIC","XPTO;ABRA",NULL,123,'B',1);
	t2 = UniCurr_new_fromString(string1,'|');
	t3 = UniCurr_new_fromString(string2,'|');
	t4 = UniCurr_new_fromString(string3,'|');
	t5 = UniCurr_new_fromString(string4,'|');
	tt1 = Teacher_new("Adolfo","Dias",123);
	tt2 = Teacher_new_FromString(string5,'|');


	/*Teacher_line2CDB(tt1);
	Teacher_line2CDB(tt2);
*/
	puts("------------------------------------------------");
	
	
	UniCurr_line2CDB(t1);
	UniCurr_line2CDB(t2);
	UniCurr_line2CDB(t3);
	UniCurr_line2CDB(t4);
	UniCurr_line2CDB(t5);
	
	/*UniCurr_toString(t1);
	UniCurr_toString(t2);
	UniCurr_toString(t3);
	UniCurr_toString(t4);
	UniCurr_toString(t5);*/


	UniCurr_destroyer(t1);
	UniCurr_destroyer(t2);
	UniCurr_destroyer(t3);
	UniCurr_destroyer(t4);
	UniCurr_destroyer(t5);
	Teacher_destroy(tt2);
	Teacher_destroy(tt1);

return 0;	
}
