#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "newtypes.h"
#include "Board.h"
struct emptycell_t{
	Cell super;
};

typedef struct emptycell_t EmptyCell;

char EmptyCell_getView(EmptyCell* this);
void EmptyCell_touch(EmptyCell* this);
void EmptyCell_cleanup(EmptyCell* this);
void EmptyCell_delete(EmptyCell* this);
void EmptyCell_init(EmptyCell* this,int l, int c);
EmptyCell* EmptyCell_new(int l, int c);

#endif
