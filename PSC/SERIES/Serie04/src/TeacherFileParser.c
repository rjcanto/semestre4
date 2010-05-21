/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/
Teacher * lineProcessor_Teacher(char * inLine){
	Teacher * newTeacher;
	int c;
	int field = 0;
	char * prevPTR=inLine-1;
	char * tmpstring;
	assert(inLine != NULL);
	newTeacher = (Teacher *)malloc(sizeof(Teacher));
	
	while((c = *(inLine)) != '\0'){
		if (c == MAIN_FIELD_SEPARATOR || c=='\r' || c == '\n'){
			tmpstring = (char*) malloc (inLine - prevPTR -1);
			strncpy(tmpstring, prevPTR, inLine - prevPTR -1);
			switch(field){
					case 0:
						sscanf(tmpstring,"%d",&(newTeacher->mec_number));
						free(tmpstring);
						break;
					case 1:
						newTeacher->name = tmpstring;
						break;
					case 2:
						newTeacher->email = tmpstrinf;
						break;
			}
			++field;
			prevPTR =  inLine;
		}
	}
	return newTeacher;
}
