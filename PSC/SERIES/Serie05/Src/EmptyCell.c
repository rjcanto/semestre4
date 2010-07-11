#include "EmptyCell.h"
#include "Board.h"
static const  int difLin[] = {-1,-1,-1, 0, 0, 1, 1, 1 }, difCol[] = {-1, 0, 1,-1, 1,-1, 0, 1 };
static int dL_size = 8; 

char EmptyCell_getView(EmptyCell* this){
	return (this->number == 0) ? VIEW : (char)('0'+this->number); 
}

void EmptyCell_touch(EmptyCell* this){
	int i;
	if (Cell_isShown(&(this->super))) return;
	
	Cell_show(&(this->super));
	/*Board b = Minesweeper.board;*/
	
	for (i=0; i< dL_size; ++i){
		if (Board_isBomb(this->super.board,this->line + difLin[i], this->colunm + difCol[i]))
			++this->number;
	}
	if (this->number == 0){
		for(i=0; i< dL_size ; ++i)
			Board_touch(this->super.board,this->line + difLin[i], this->colunm + difCol[i]);
	}
}

void EmptyCell_cleanup(EmptyCell* this){
	if (this == NULL) return;
	this->line=this->colunm=0;
}
void EmptyCell_delete(EmptyCell* this){
	if (this == NULL) return;
	EmptyCell_cleanup(this);
	free(this);
}
static Cell_Methods emptycell_vtable={
	(CELL_VOID_CAST) EmptyCell_delete,
	(CELL_CHAR_CAST) EmptyCell_getView,
	(CELL_VOID_CAST) EmptyCell_touch,
	(CELL_BOOLEAN_CAST) Cell_isBomb	
};
  

void EmptyCell_init(EmptyCell* this,Board* board,int l, int c){
	Cell_init(&(this->super),board);
	this->super.vptr=&emptycell_vtable;
	this->line=l; 
	this->colunm=c;
	this->number=0;
}

EmptyCell* EmptyCell_new(Board* board,int l, int c){
	EmptyCell* this;
	this =(EmptyCell*)calloc(1,sizeof(EmptyCell));
	EmptyCell_init(this,board,l,c);
	return this;
}


