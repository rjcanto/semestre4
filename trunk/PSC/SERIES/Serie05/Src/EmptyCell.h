#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "Cell.h"
struct board_t;

typedef struct emptycell_t{
	Cell super;
	int number;
	int line;
	int colunm;
}EmptyCell;

void EmptyCell_delete(EmptyCell* this);
void EmptyCell_cleanup(EmptyCell* this);
void EmptyCell_init(EmptyCell* this,int l, int c);
void EmptyCell_touch_count(EmptyCell* this,struct board_t* board);
EmptyCell* EmptyCell_new(int l, int c);

#endif
