#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"
#include "newtypes.h"
#include "Command.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_COMMAND_INPUT 20
struct Board;
struct miner{
	Board board;
	boolean exit;	
};
typedef struct miner Miner;

extern Miner MineSweeper;

#endif
