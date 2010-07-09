#include "Minesweeper.h"
Miner MineSweeper;
static void MineSweeper_init(Miner* this){
	if (this == NULL) return;
	this->exit = false;
}
static void MineSweeper_cleanup(Miner* this){
	if (this == NULL) return;
	this->exit = false;
}

static void MineSweeper_newGame(){
	puts("[NEW GAME]");
	MineSweeper_cleanup(&MineSweeper);
	MineSweeper_init(&MineSweeper);	
}
static boolean	MineSweeper_isSolved(){
	puts("[ISSOLVED]");
	return false;
}
static void 	MineSweeper_touch(int l, int c){
	puts("[TOUCH]");
}
static void 	MineSweeper_showAll(){
	puts("[SHOWALL]");
}
static void 	MineSweeper_flag(int l, int c){
	puts("[FLAG]");
}
static void 	MineSweeper_exit(){
	puts("[EXIT]");
	MineSweeper.exit = true;
}
Game_Methods g_Vtable={
	MineSweeper_newGame,
	MineSweeper_isSolved,
	MineSweeper_touch,
	MineSweeper_showAll,
	MineSweeper_flag,
	MineSweeper_exit
};

static void MineSweeper_init_GameVtable(Miner* this){
	this->gvptr = &g_Vtable;
}
int main(int argc, char** argv){
	char input[20];
	
	MineSweeper_init(&MineSweeper);
	MineSweeper_init_GameVtable(&MineSweeper);
	
	Command_load(MineSweeper.gvptr,"Commands.cfg");
	while(!MineSweeper.exit){
		printf("> ");
		if (fgets(input,20,stdin))
			Command_execute(input);
		
	}
	Command_unload();
	/*MineSweeper_cleanup(&MineSweeper);*/
	return EXIT_SUCCESS;
}
