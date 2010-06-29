#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h>
#include "newtypes.h"
#include "Exception.h"

struct board_t;
typedef struct board_t Board;

typedef struct board_methods{
	
	
}Board_Methods;


struct board_t{
	Board_Methods* vptr;
};
boolean isSolved(Board* this);
void Board_print(Board* this);
boolean Board_isValid(Board* this, int l, int c);
boolean Board_isBomb(Board* this, int l, int c);
void Board_touch(Board* this, int l, int c);
void Board_showAll(Board* this);
void Board_flag(Board* this, int l, int c);

#endif
