#include "Minesweeper.h"
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

int main(int argc, char** argv){
	char input[MAX_COMMAND_INPUT];
	MineSweeper_init(&MineSweeper);
	Command_load("Commands.cfg");
	while(!MineSweeper.exit){
		Board_print(&(MineSweeper.board));
		printf("> ");
		if (fgets(input,MAX_COMMAND_INPUT,stdin))
			Command_execute(input);
	}
	MineSweeper_cleanup(&MineSweeper);
	return EXIT_SUCCESS;
}
