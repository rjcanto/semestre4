#include "Command.h"
Cmds Commands_Array;
Miner* mine;
const static Command_Methods cmd_vtable={
	(const void (*) (Command*)) Command_cleanup,
	(const char (*) (Command*))Command_prefix,
	(const void (*) (Command*,char*))Command_exec,
	(const void (*) (Command*))Command_help,
	(const char*(*) (Command*))Command_syntax
};

char 	Command_prefix(Command* this){
	puts("Method Command_prefix not yet implemeted!");
	return 0;
}
char* 	Command_syntax(Command* this){
	return ""; 

}
void 	Command_exec(Command* this,char* line){
	puts("Method Command_exec not yet implemeted!");	
}
void 	Command_help(Command* this){
	puts("Method Command_help not yet implemeted!");
}

static Command* Command_newInstance(const char* libName){
	void* hp;
	Command* (*newCommand)();
	Command* t;
	char tmp[50];
	
	if (sprintf(tmp,"./%sCmd.so",libName) == 0){return NULL;}
	
	hp = dlopen(tmp,RTLD_NOW);

	if (hp == NULL) {puts(dlerror());return NULL;}
	
	*(void**)&newCommand = dlsym(hp,"newInstance");
			
	if(newCommand == NULL){dlclose(hp);return NULL;}
	t = newCommand();
	t->handler =  hp;
	return t;
}

void Command_unload(Command* t){
	void* hp = t->handler;
	(t)->vptr->dtor(t);
	dlclose(hp);	
}
static char * removeNL(char * str) {
	while( (*str != ' ') && (*str != '\r') && (*str != '\n') && (*str != 0) )str++;
		*str = 0;
	return str;
}
static Command** Commands_Array_new(int nbr_commands){
	Command** arr =  (Command**)calloc(nbr_commands,sizeof(Command*));
	assert (arr != NULL);
	return arr;
}
boolean Command_load(char* cfgFile){
	int nLines;
	FILE* fin=NULL;
	char buffer[BUFFER];

	
	TRY {
		mine=&MineSweeper;
		assert ((fin = fopen(cfgFile,"rb"))!= NULL);
		fseek(fin,0,SEEK_CUR);
		
		for (nLines=0 ; fgets(buffer,sizeof(buffer),fin) != NULL ; ++nLines) ;
		rewind(fin);

		Commands_Array.length=nLines;
		
		if (((Commands_Array.cmds) = Commands_Array_new(nLines)) == NULL){
			
			THROW(UNABLE_TO_READ_FILE_EXCEPTION);
			
		}else{
			int i;
			Command* com;
			for(i=0; i< nLines ; ++i){
				fgets(buffer,BUFFER,fin);
				removeNL(buffer);
				if ((com  = Command_newInstance(buffer)) == NULL){
					THROW(UNABLE_TO_LOAD_LIBRARY_EXCEPTION) ;
				}
				(Commands_Array.cmds[i])=com;
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
	
	if (line == NULL || *line == 0){ return;
	}else{
	char prefix = toupper(*line);
	char* tmp = (char*)calloc(50,1);
	int i;
	tmp=removeNL(line);
	
	
	for(i=0 ; i< Commands_Array.length ; ++i)
		
		if ((Commands_Array.cmds[i])->vptr->prefix((Commands_Array.cmds[i])) == prefix) {
			(Commands_Array.cmds[i])->vptr->exec((Commands_Array.cmds[i]),tmp+1);
			return;
		}
		printf("Invalid command %c\n",prefix);	
	}
		
}

int Command_parseCol(char* txt){
	int val=0;
	char c;
	while (*txt && !((*txt >= 'A' && *txt<='Z')|| (*txt >= 'a' && *txt<='z')))
		++txt;
	
	if (*txt && ((*txt >= 'A' && *txt<='Z')|| (*txt >= 'a' && *txt<='z')) ) {c=*txt; val+=toupper(c)-'A'; }
	return val;	
}
int Command_parseLine(char* txt){
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



void Command_init(Command* t){
	t->vptr= &cmd_vtable;
}
void Command_cleanup(Command* t){
	t->vptr = NULL;
}
