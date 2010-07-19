#ifndef BOMBCELL_H
#define BOMBCELL_H
#include "Cell.h"
#include "newtypes.h"

typedef struct bomcell_t{
	Cell super;
	boolean exploded;	
}BombCell;
 
BombCell* BombCell_new();
void BombCell_init(BombCell* this);
void BombCell_delete(BombCell* this);
void BombCell_cleanup(BombCell* this);

#endif
