#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "newtypes.h"
/*#include "Board.h"*/
struct emptycell_t{
	Cell super;
	int number;
	int line;
	int colunm;
};

typedef struct emptycell_t EmptyCell;

char EmptyCell_getView(EmptyCell* this);
void EmptyCell_touch(EmptyCell* this);
void EmptyCell_cleanup(EmptyCell* this);
void EmptyCell_delete(EmptyCell* this);
void EmptyCell_init(EmptyCell* this,Board* board,int l, int c);
EmptyCell* EmptyCell_new(Board* board,int l, int c);

#endif
