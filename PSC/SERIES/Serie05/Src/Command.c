#include "Command.h"

/*const Command cmds[];*/

const Cmds this;

const static Command_Methods cmd_vtable={
	Command_dtor,
	Command_prefix,
	Command_exec,
	Command_help,
	Command_syntax
};

	char 	Command_prefix(){
		puts("Method not yet implemeted!");
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



	boolean Command_load(char* cfgFile){
		int nLines;
		BufferedReader fin;
		
		TRY {
			fin = new BufferedReader( new FileReader(cfgFile) );
			fin.mark(1024);
			for (nLines=0 ; fin.readLine()!=null ; ++nLines) ;
			fin.reset();
			cmds = new Command[nLines];
			for(int i=0; i< nLines ; ++i)
				cmds[i] = (Command) Class.forName(fin.readLine()+"Cmd").newInstance();
			fin.close();
		} CATCH (Exception e) {
			System.err.println("Error reading file "+cfgFile+". "+e.getMessage()); return false;
		}
		return true;		
	}


	void 	Command_execute(char* line){
		if (line == NULL || *line == 0) return;
		char prefix = toupper(*line);
		
		for(int i=0 ; i< this.cmds.length ; ++i)
			if (this.cmds[i].prefix() == prefix) {
				this.cmds[i].exec(line+1);
				return;
			}
		printf("Invalid command %c",prefix);		
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
		
		if (*txt && ((*txt >= 'A' && *txt<='Z')|| (*txt >= 'a' && *txt<='z')) ) {c=*txt;t val+=toupper(c)-'A'; }
		return val;	
	}



	
	void Command_dtor(void* this);
	Command* Command_ctor();
	void Command_init(void* this);
	void Command_clean(void* this);
