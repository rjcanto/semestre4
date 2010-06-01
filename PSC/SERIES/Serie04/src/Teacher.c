#include "Teacher.h"

Teacher* Teacher_new(char * name, char * email, unsigned short mec_number){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	Teacher_init(this, name,email,mec_number);
	return this;	
}

Teacher* Teacher_new_FromString(const char* line, char delimiter){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));

	int idx=0;
	char * tmp=0;
	
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->mec_number=0;
		idx+=1;
	}else{
		idx+=strlen(tmp)+1;
		if (sscanf(tmp,"%hu",&(this->mec_number)) == 0 )
		{
			puts("Not a Number");
			this->mec_number =0;
			idx+=1;
		}
	}
	free(tmp);tmp=NULL;
	
	
	/*Processa o Nome do Docente*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->name=NULL;
		idx+=1;
		free(tmp);tmp=NULL;
	}else{
		this->name=tmp;
		idx+=strlen(tmp)+1;
	}
	/*Processa o Email*/
	tmp=get_next_field(line+idx,delimiter);
	if (tmp == NULL){
		this->email=NULL;
		free(tmp);tmp=NULL;
	}else{
		this->email=tmp;
	}
	
	return this;	
}

void Teacher_init(Teacher* this, char * name, char * email, unsigned short mec_number){
	if (name != NULL){
		char *n=(char*)malloc(strlen(name)+1);
		strcpy(n,name);
		this->name=n;
	}else{
		this->name=NULL;
	}
	if (email != NULL){
		char* n =(char*)malloc(strlen(email)+1);
		strcpy(n,email);
		this->email =n;
	}else{
		this->email=NULL;
	}	
	this->mec_number = mec_number;
}

void Teacher_toString(Teacher* this){
	
	printf ("Number: %5hu\tName: %-40.40s\tEmail: %-40.40s\n",this->mec_number,(this->name==NULL)?"NULL":this->name,(this->email==NULL)?"NULL":this->email);
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
