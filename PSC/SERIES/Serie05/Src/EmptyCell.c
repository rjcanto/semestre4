#include "EmptyCell.h"

static const  int difLin[] = {-1,-1,-1, 0, 0, 1, 1, 1 }, difCol[] = {-1, 0, 1,-1, 1,-1, 0, 1 };
static int dL_size = 8; 
static int lin, col;
static int number;

char EmptyCell_getView(EmptyCell* this){
	return number==0 ? ' ' : (char)('0'+number); 
}

void EmptyCell_touch(EmptyCell* this){
	int i;
	if (CELL_ISSHOWN(&(this->super))) return;
	Cell_show(&(this->super));
	/*Board b = Minesweeper.board;*/
	for (i=0; i< dL_size; ++i){
		if (Board_isBomb(Board_getpointer(),lin + difLin[i], col + difCol[i]))
			++number;
	}
	if (number == 0)
		for(i=0; i< dL_size ; ++i)
			Board_touch(Board_getpointer(),lin + difLin[i], col + difCol[i]);
}

void EmptyCell_cleanup(EmptyCell* this){
	if (this == NULL) return;
	this->super.vptr->dtor(&(this->super));
	lin=col=0;
}
void EmptyCell_delete(EmptyCell* this){
	if (this == NULL) return;
	EmptyCell_cleanup(this);
	free(this);
}
static Cell_Methods emptycell_vtable={
	(CELL_VOID_CAST) EmptyCell_cleanup,
	(CELL_CHAR_CAST) EmptyCell_getView,
	(CELL_VOID_CAST) EmptyCell_touch,
	(CELL_BOOLEAN_CAST) Cell_isBomb	
};
  

void EmptyCell_init(EmptyCell* this,int l, int c){
	Cell_init(&(this->super));
	this->super.vptr=&emptycell_vtable;
	lin=l; 
	col=c;
}

EmptyCell* EmptyCell_new(int l, int c){
	EmptyCell* this;
	this =(EmptyCell*)calloc(1,sizeof(EmptyCell));
	EmptyCell_init(this,l,c);
	return this;
}


