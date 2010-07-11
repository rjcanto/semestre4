#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "newtypes.h"
#include "Command.h"
#include "GameInterface.h"
#include "Board.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_COMMAND_INPUT 50
struct miner{
	Game_Methods* gvptr;
	Board	board;
	boolean exit;	
};
typedef struct miner Miner;

#endif
