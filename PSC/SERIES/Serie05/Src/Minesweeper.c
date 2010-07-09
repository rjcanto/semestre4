#include "Minesweeper.h"
Miner MineSweeper;

#define BOARD_ADDR &(MineSweeper.board)

static void MineSweeper_init(Miner* this){
	if (this == NULL) return;
	Board_init(&(this->board));
	this->exit = false;
}
static void MineSweeper_cleanup(Miner* this){
	if (this == NULL) return;
	Board_Cleanup(&(this->board));
	this->exit = false;
}

static void MineSweeper_newGame(){
	MineSweeper_cleanup(&MineSweeper);
	MineSweeper_init(&MineSweeper);	
}
static boolean	MineSweeper_isSolved(){
	return Board_isSolved(BOARD_ADDR);
}
static void 	MineSweeper_touch(int l, int c){
	Board_touch(BOARD_ADDR,l,c);
}
static void 	MineSweeper_showAll(){
	Board_showAll(BOARD_ADDR);	
}
static void 	MineSweeper_flag(int l, int c){
	Board_flag(BOARD_ADDR,l,c);
}
static void 	MineSweeper_exit(){
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
	char input[MAX_COMMAND_INPUT];
	MineSweeper_init(&MineSweeper);
	MineSweeper_init_GameVtable(&MineSweeper);
	
	Command_load(MineSweeper.gvptr,"Commands.cfg");
	while(!MineSweeper.exit){
		Board_print(&(MineSweeper.board));
		printf("> ");
		if (fgets(input,MAX_COMMAND_INPUT,stdin))
			Command_execute(input);
		
	}
	/*MineSweeper_cleanup(&MineSweeper);*/
	return EXIT_SUCCESS;
}