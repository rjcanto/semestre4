#include "EmptyCell.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "newtypes.h"
#include "Board.h"

static const  int difLin[] = {-1,-1,-1, 0, 0, 1, 1, 1 }, difCol[] = {-1, 0, 1,-1, 1,-1, 0, 1 };
static int dL_size = 8; 

/**
 * Mostra o estado da célula
 * */
static char EmptyCell_getView(EmptyCell* this){
	return (this->number == 0) ? VIEW : (char)('0'+this->number); 
}

/**
 * Contabiliza o numero de bombas para uma célula à vista
 * */
void EmptyCell_touch_count(EmptyCell* this,Board* board){
	int i;
	for (i=0; i< dL_size; ++i){
		if (Board_isBomb(board,this->line + difLin[i], this->colunm + difCol[i]))
			++this->number;
	}
	if (this->number == 0){
		for(i=0; i< dL_size ; ++i)
			Board_touch(board,this->line + difLin[i], this->colunm + difCol[i]);
	}

}

/**
 * Muda o estado de uma celula
 * */
static void EmptyCell_touch(EmptyCell* this, Board* board){
	
	if (Cell_isShown(&(this->super))){return;}
	Cell_show(&(this->super));
	
	EmptyCell_touch_count(this, board);
}


/*
 * Destructores e Constructores e afins
 * */
void EmptyCell_cleanup(EmptyCell* this){
	if (this == NULL) return;
	this->line=this->colunm=0;
}
void EmptyCell_delete(EmptyCell* this){
	if (this == NULL) return;
	EmptyCell_cleanup(this);
	free(this);
}
/**
 * Tabela de Métodos virtuais
 * */
static Cell_Methods emptycell_vtable={
	(CELL_VOID_CAST) EmptyCell_delete,
	(CELL_CHAR_CAST) EmptyCell_getView,
	(void (*)(Cell*,Board*)) EmptyCell_touch,
	(CELL_BOOLEAN_CAST) Cell_isBomb	
};
  

void EmptyCell_init(EmptyCell* this,int l, int c){
	Cell_init(&(this->super),'E');
	this->super.vptr=&emptycell_vtable;
	this->line=l; 
	this->colunm=c;
	this->number=0;
}

EmptyCell* EmptyCell_new(int l, int c){
	EmptyCell* this;
	this =(EmptyCell*)calloc(1,sizeof(EmptyCell));
	EmptyCell_init(this,l,c);
	return this;
}


