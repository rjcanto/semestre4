#include "Teacher.h"

Teacher* Teacher_new(char * name, char * email, unsigned short mec_number){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	Teacher_init(this, name,email,mec_number);
	return this;	
}

char* copy_field(char * src, char * end){
	char * dst;
	*(end) = '\0';
	dst = (char*)malloc(strlen(src) + 1);
	strcpy(dst, src);
	return dst;
}
char* get_next_field(char * line, const char delimiter){
	char * myline; 

	char * field;
	char * cursor;
	
	if (line == NULL || *line == 0 || *line == delimiter) return NULL;

	/*
	 * Copia a string de entrada para poder alterar, sem prejudicar a 
	 * original
	 * */
	myline = (char*)malloc(strlen(line)+1);
	strcpy(myline, line);
	field = myline;
	cursor	= myline; 
		
	while (*cursor && (*cursor != delimiter))
		++cursor;

	field= copy_field(myline,cursor);
	/*
	 *Liberta o espaço ocupado anteriormente pela copia da string
	 * */ 
	free(myline);
	return ( cursor - line - 1 == 0)? NULL:field;
}


Teacher* Teacher_new_FromString(char* line, char delimiter){
	Teacher* this = (Teacher*)malloc(sizeof(Teacher));
	
	int idx=0;
	char * tmp =line;
	
	tmp = get_next_field(line,delimiter);
	
	 if ( sscanf(tmp, "%hu", &(this->mec_number)) == 0 ) {puts("Not a Number");return NULL;};
	 
		idx+=strlen(tmp)+1;
	
	this->name=get_next_field(line + idx ,delimiter);
		idx+=strlen(this->name)+1;
	
	this->email=get_next_field(line + idx  ,delimiter);
		free(tmp);
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
	printf ("Number: %5hu\tName: %-40.40s\tEmail: %-40.40s\n",this->mec_number,this->name,this->email);
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
	 Teacher * t1 = t1;
	 Teacher * t2 = t2;
	 char string[]="819|Acilina Nascimento Caneco|d819@deetc.isel.pt";
	 
	 
	t1 = Teacher_new("Adolfo","Dias",123);
	t2 = Teacher_new_FromString(string,'|');
	
	Teacher_toString(t1);
	Teacher_toString(t2);
	
	Teacher_destroy(t1);
	Teacher_destroy(t2);

return 0;	
}
