#ifndef BOMBCELL_H
#define BOMBCELL_H
#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "newtypes.h"
#include "Board.h"

struct bomcell_t{
	Cell super;
	boolean exploded;	
};
typedef struct bomcell_t BombCell;

char BombCell_getView(BombCell* this);
void BombCell_touch(BombCell* this);
boolean BombCell_isBomb(BombCell* this);

BombCell* BombCell_new(Board * b);
void BombCell_init(BombCell* this,Board * b);
void BombCell_delete(BombCell* this);
void BombCell_cleanup(BombCell* this);

#endif
