/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/

#define MAIN_FIELD_SEPARATOR 	'|'
#define SUB_FIELD_SEPARATOR		';'
typedef 	char	byte;

typedef struct prof_type{
	char *			name;
	char *			email;
	unsigned short	mec_number;
} Prof;

typedef struct dep_node_list{
	node 	dep_node;
	char *	uniCurr;
} Dep_list;

typedef struct uniCurr_type{
	char *			uniCurr;
	char *			className;
	Dep_list*		strongDep;
	Dep_list*		weakDep;
	unsigned short	mec_number:
	byte			type;
	byte			semester;	
} UC;

typedef struct UC_Node_List{
	node		head;
	struct UC * uc_record;	
} UC_list;

typedef struct Prof_Node_List{
	node			head;
	struct Prof *	prof_record;
} Prof_list;

Prof * lineProcessor_Prof(char * inLine){
	Prof * newProf;
	int c;
	int field = 0;
	char * prevPTR=inLine-1;
	char * tmpstring;
	assert(inLine != NULL);
	newProf = (Prof *)malloc(sizeof(Prof));
	
	while((c = *(inLine)) != '\0'){
		if (c == MAIN_FIELD_SEPARATOR || c=='\r' || c == '\n'){
			tmpstring = (char*) malloc (inLine - prevPTR -1);
			strncpy(tmpstring, prevPTR, inLine - prevPTR -1);
			switch(field){
					case 0:
						sscanf(tmpstring,"%d",&(newProf->mec_number));
						free(tmpstring);
						break;
					case 1:
						newProf->name = tmpstring;
						break;
					case 2:
						newProf->email = tmpstrinf;
						break;
			}
			++field;
			prevPTR =  inLine;
		}
	}
	return newProf;
}

void fileProcessor_Prof(FILE * file){

	
}
