#include "BombCell.h"

char BombCell_getView(BombCell* this){
	return ((this->exploded) ? '@' : '+'); 
}
void BombCell_touch(BombCell* this){
	Cell_show(&(this->super));
	this->exploded = true;
	puts("BUMMMM.");
	Board_showAll(Board_getpointer());
}

boolean BombCell_isBomb(BombCell* this){return true;}

void BombCell_cleanup(BombCell* this){
	if (this == NULL) return;
	this->super.vptr->dtor(&(this->super));
	this->exploded = false;
}
void BombCell_delete(BombCell* this){
	if (this == NULL) return;
	BombCell_cleanup(this);
	free(this);
}

static Cell_Methods bombcell_vtable={
	(CELL_VOID_CAST) BombCell_cleanup,
	(CELL_CHAR_CAST) BombCell_getView,
	(CELL_VOID_CAST) BombCell_touch,
	(CELL_BOOLEAN_CAST)BombCell_isBomb
};


void BombCell_init(BombCell* this){
	Cell_init(&(this->super));
	this->super.vptr = &bombcell_vtable;
	this->exploded = false;
}
BombCell* BombCell_new(){
	BombCell* this =(BombCell*)calloc(1,sizeof(BombCell));
	assert(this != NULL);
	BombCell_init(this);
	return this;
}

