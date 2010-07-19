#include "BombCell.h"
#include "Board.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Board.h"

/**
 * Mostra a celula
 * */
static char BombCell_getView(BombCell* this){
	return ((this->exploded) ? '@' : '+'); 
}

/**
 * Muda o estado da celula
 * */
static void BombCell_touch(BombCell* this, Board* board){
	Cell_show(&(this->super));
	this->exploded = true;
	puts("BUMMMM.");
	board->over=true;
	Board_showAll(board);
}

/**
 * indica que é uma bomba
 * */
static boolean BombCell_isBomb(BombCell* this){return true;}

/**
 *  Destrutores/Construtores e afins
 * */
void BombCell_cleanup(BombCell* this){
	if (this == NULL) return;
	this->exploded = false;
}
void BombCell_delete(BombCell* this){
	if (this == NULL) return;
	BombCell_cleanup(this);
	free(this);
}

static Cell_Methods bombcell_vtable={
	(CELL_VOID_CAST) BombCell_delete,
	(CELL_CHAR_CAST) BombCell_getView,
	(void (*)(Cell*,Board*)) BombCell_touch,
	(CELL_BOOLEAN_CAST)BombCell_isBomb
};


void BombCell_init(BombCell* this){
	Cell_init(&(this->super),'B');
	this->super.vptr = &bombcell_vtable;
	this->exploded = false;
}
BombCell* BombCell_new(){
	BombCell* this =(BombCell*)calloc(1,sizeof(BombCell));
	assert(this != NULL);
	BombCell_init(this);
	return this;
}

