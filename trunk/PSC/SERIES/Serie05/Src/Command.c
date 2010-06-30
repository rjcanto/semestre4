#include "Command.h"

const static Command_Methods cmd_vtable={
	(const void (*) (Command*)) Command_cleanup,
	(const char (*) ())Command_prefix,
	(const void (*) (char*))Command_exec,
	(const void (*) ())Command_help,
	(const char*(*) ())Command_syntax
};

char 	Command_prefix(){
	puts("Method not yet implemeted!");
	return 0;
}
char* 	Command_syntax(){
	return ""; 

}
void 	Command_exec(char* line){
	puts("Method not yet implemeted!");	
}
void 	Command_help(){
	puts("Method not yet implemeted!");
}

static boolean Command_newInstance(char* libName,Command* t){
	void* hp;
	Command* (*newCommand)();
	
	hp = dlopen(libName,RTLD_NOW);
	
	if (!hp) return false;
	*(void**)&newCommand = dlsym(hp,"newInstance");
	if(!newCommand){ dlclose(hp);return false;}
	t = newCommand();
	t->handler =  hp;
	return true;
}

void Command_unload(Command* t){
	void* hp = t->handler;
	(t)->vptr->dtor(t);
	dlclose(hp);	
}

boolean Command_load(char* cfgFile){
	int nLines;
	FILE* fin=NULL;
	char buffer[BUFFER];
	
	TRY {
		assert ((fin = fopen(cfgFile,"rb"))== NULL);
		fseek(fin,BUFFER,SEEK_SET);

		for (nLines=0 ; fgets(buffer,BUFFER,fin) != NULL ; ++nLines) ;

		rewind(fin);
		Commands_Array.length=nLines;

		if ((Commands_Array.cmds = (Command*)calloc(nLines,sizeof(Command))) == NULL){
			THROW(UNABLE_TO_READ_FILE_EXCEPTION);
		}else{
			int i;
			for(i=0; i< nLines ; ++i){
				fgets(buffer,BUFFER,fin);
				sprintf(buffer,"%sCmd.so",buffer);
				if (!Command_newInstance(buffer,(Commands_Array.cmds+i*sizeof(Command)))){
					THROW(UNABLE_TO_LOAD_LIBRARY_EXCEPTION) ;
				}
			}
			fclose(fin);
		}
	}CATCH (UNABLE_TO_READ_FILE_EXCEPTION){
		printf("Error reading file %s.\n",cfgFile); 
		fclose(fin);
		return false;
	}CATCH (UNABLE_TO_LOAD_LIBRARY_EXCEPTION){
		printf("Error loading library %s.\n",buffer); 
		fclose(fin);
		return false;
	}TRY_END;
	return true;		
}


void 	Command_execute(char* line){
	if (line == NULL || *line == 0) return;
	else{
	char prefix = toupper(*line);
	int i;
	for(i=0 ; i< Commands_Array.length ; ++i)
		if (Commands_Array.cmds[i].vptr->prefix() == prefix) {
			Commands_Array.cmds[i].vptr->exec(line+1);
			return;
		}
		printf("Invalid command %c",prefix);	
	}	
}


const int Command_parseLine(char* txt){
	int val=0;
	char c;
	while(*txt && !(*txt >= '0' && *txt<='9')){
		++txt;
	}
	while(*txt && (*txt >= '0' && *txt<='9')){
		c=*txt;
		val*=10; val+=c-'0';			
	}
	return val-1;		
}

const int Command_parseCol(char* txt){
	int val=0;
	char c;
	while (*txt && !((*txt >= 'A' && *txt<='Z')|| (*txt >= 'a' && *txt<='z')))
		++txt;
	
	if (*txt && ((*txt >= 'A' && *txt<='Z')|| (*txt >= 'a' && *txt<='z')) ) {c=*txt; val+=toupper(c)-'A'; }
	return val;	
}

void Command_init(Command* t){
	t->vptr= &cmd_vtable;
}
void Command_cleanup(Command* t){
	t->vptr = NULL;
}
