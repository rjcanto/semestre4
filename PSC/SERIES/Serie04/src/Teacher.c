#include "Teacher.h"

Teacher* Teacher_new(char * name, char * email, unsigned short mec_number){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	Teacher_init(this, name,email,mec_number);
	return this;	
}

Teacher* Teacher_new_FromString(const char* line, char delimiter){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	int size=0;
	int idx=0;
	char * value=0;
	
	/*Processa o numero de Docente*/
	value=get_next_field(line+idx,delimiter);
	
	if (value == NULL){
		this->mec_number=0;
		idx+=1;
	}else{
		idx+=strlen(value)+1;
		if (sscanf(value,"%hu",&(this->mec_number)) == 0 )
		{
			puts("Not a Number");
			this->mec_number =0;
			idx+=1;
		}
	}
	size+=sizeof(this->mec_number);
	free(value);value=NULL;
	
	
	/*Processa o Nome do Docente*/
	value=get_next_field(line+idx,delimiter);
	if (value == NULL){
		this->name=NULL;
		idx+=1;
		size+=1;
		free(value);value=NULL;
	}else{
		int tmp_size=strlen(value)+1;
		this->name=value;
		idx+=tmp_size;
		size+=tmp_size;
	}
	/*Processa o Email*/
	value=get_next_field(line+idx,delimiter);
	if (value == NULL){
		this->email=NULL;
		size+=1;
		free(value);value=NULL;
	}else{
		this->email=value;
		size+=strlen(value)+1;
	}
	this->totalsize=size;
	return this;	
}
/*	
Campo	Designação do Campo	Posição	Comprimento		Conteudo	OBS
 01		mec_number			   	01	2 bytes			Fixo
 02		Tamanho Nome			03	1 byte			Fixo		Indica o tamanho do texto referente ao Nome
 03		Nome					04  -----------		Variável	Comprimento dado pelo campo 02
 04		Tamanho email			--	1 byte			Variável	Indica o tamanho do texto referente ao Email
 05		Email					--	-----------		Variável	Comprimento dado pelo campo 04
*/
void Teacher_line2CDB2(Teacher* this){
	printf("%hu%c%s%c%s\n",this->mec_number,\
							(this->name != NULL)?(char)strlen(this->name):0,\
							(this->name != NULL)?this->name:"",\
							(this->email != NULL)?(char)strlen(this->email):0,\
							(this->email != NULL)?this->email:""\
							);
}

void Teacher_line2CDB(Teacher* this){
	char* cdb_line=(char*)malloc((this->totalsize)+2);/* ???? */
	int ret;
	ret=sprintf(cdb_line,"%hu%c%s%c%s",this->mec_number,\
							(this->name != NULL)?(char)strlen(this->name):0,\
							(this->name != NULL)?this->name:"",\
							(this->email != NULL)?(char)strlen(this->email):0,\
							(this->email != NULL)?this->email:""\
							);
	printf(">>>>>>>> %u >> %u (%u)\n",this->totalsize, ret,strlen(cdb_line) );
	puts(cdb_line);
	
	if (cdb_line != NULL){
		free(cdb_line);
		cdb_line=NULL;						
	}
}


void Teacher_init(Teacher* this, char * name, char * email, unsigned short mec_number){
	int size=0;
	int value_size=0;
	char *n=NULL;
	
	if (name != NULL){
		value_size=strlen(name)+1;
		n=(char*)malloc(value_size);
		strcpy(n,name);
		this->name=n;
		size+=value_size;
		n=NULL;
	}else{
		this->name=NULL;
		size+=1;
	}
	if (email != NULL){
		value_size=strlen(email)+1;
		n =(char*)malloc(value_size);
		strcpy(n,email);
		this->email =n;
		size+=value_size;
		n=NULL;
	}else{
		this->email=NULL;
		size+=1;
	}	
	this->mec_number = mec_number;
	size+=sizeof(this->mec_number);
	this->totalsize=size;
}

void Teacher_toString(Teacher* this){
	
	printf ("Number: %5hu\tName: %-40.40s\tEmail: %-40.40s\nTotal Size: %hu\n",this->mec_number,(this->name==NULL)?"NULL":this->name,(this->email==NULL)?"NULL":this->email,this->totalsize);
}

void Teacher_toString_debug(Teacher* this){
	printf ("Number: %5hu (%u)\tName: %-40.40s (%u)\tEmail: %-40.40s(%u)\nTotal Size: %hu\n",this->mec_number,sizeof(this->mec_number),\
	(this->name==NULL)?"NULL":this->name,(this->name==NULL)?0:strlen(this->name)+1,\
	(this->email==NULL)?"NULL":this->email,(this->email==NULL)?0:strlen(this->email)+1,\
	this->totalsize);
}

void Teacher_cleanup(Teacher* this){
	if (this == NULL) return;
	
	if(this->name != NULL ){
		free(this->name);	this->name = NULL;
	}
	if(this->email != NULL){
		free(this->email);	this->email = NULL;
	}
}
void Teacher_destroy(Teacher * this){
	if (this == NULL) return;
	Teacher_cleanup(this);
	free(this);
}
/*
int main()
{
	 static char string[]="819|Acilina Nascimento Caneco|d819@deetc.isel.pt";
	 Teacher * t1 = 0;
	 Teacher * t2 = 0;
	 
	 
	 
	t1 = Teacher_new("Adolfo","Dias",123);
	Teacher_toString(t1);
	Teacher_destroy(t1);


	t2 = Teacher_new_FromString(string,'|');
	Teacher_toString(t2);
	Teacher_destroy(t2);

	

return 0;	
}
*/
