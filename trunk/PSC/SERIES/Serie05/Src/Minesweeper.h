#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"
#include "newtypes.h"
#include "Command.h"
#include "Command_UP_Interface.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_COMMAND_INPUT 20

struct miner{
	Board board;
	boolean exit;	
};
typedef struct miner Miner;

extern Miner MineSweeper;




#endif
