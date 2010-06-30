#include "Board.h"
#include "BombCell.h"
#include "EmptyCell.h"
/*
 * Métodos privados
 * */
static void Board_putBomb(Board* this,int n){
	int l,c;
	assert(n<0);
	for(l=0 ; l<LINES ; ++l)
		for(c=0; c<COLS ; ++c)
			if (this->cells[l][c] == NULL) {
				if (n==0) { 
				  this->cells[l][c]=(Cell*)BombCell_new();
				  return; 
				}
			--n;
		  }
	  assert(n == 0);	
}

static void Board_printLine(Board* this){
		int c;
		printf("   +");
		for(c =0;c < COLS;++c) printf("--");
		puts("-+");
}
/*Substituidos por Macros*/
/*boolean Board_isValid(Board* this, int l, int c){return ( l >= 0 && l < this->LINES && c >=0 &&  c< this->COLS);}*/
/*boolean Board_isSolved(Board* this){return hides==bombs;}*/
/*boolean Board_isBomb(Board* this, int l, int c){return Board_isValid(this, l, c) && cells[l][c]->vptr->isBomb(cells[l][c]);}*/

/*
 * Métodos Públicos
 * */
extern void Board_print(Board* this){
	int c,l;
	printf("%02d  ",this->bombs);
	for(c=0; c < COLS ; ++c) printf(" %c", 'A'+c);
	printf("   %02d\n", this->hides);
	Board_printLine(this);
	for(l=0 ; l<LINES ; ++l) {
		printf("%2d |",l+1);
		for(c=0; c<COLS ; ++c) {
			printf(" ");
			this->cells[l][c]->fvptr->print(this->cells[l][c]);
		}
		puts(" |");
	}
	Board_printLine(this);
}
extern void Board_touch(Board* this, int l, int c){
	if (Board_isValid(this, l, c)){
		Cell* cel = this->cells[l][c];
		if (CELL_ISSHOWN(cel) || CELL_ISFLAGGED(cel)) return;
		cel->vptr->touch(cel);
		--this->hides;
	}
}
extern void Board_showAll(Board* this){
	int l,c;
	for (l=0;l< LINES;++l)
		for(c=0;c< COLS;++c)
			this->cells[l][c]->fvptr->show(this->cells[l][c]);
	this->hides=0;
}
extern void Board_flag(Board* this, int l, int c){
	if (Board_isValid(this,l,c)){
		Cell* cel = this->cells[l][c];
		if (CELL_ISSHOWN(cel)) return;
		cel->fvptr->toggleFlag(cel);
		if (CELL_ISFLAGGED(cel)){--this->bombs;--this->hides;}
		else{++this->bombs;++this->hides;}
	}
}


/*
 * (Des)Construtores e (Des)Iniciadores
 * */
void Board_Cleanup(Board* this){
	if (this == NULL){ return;
	}else{
	int c,l;	
	for(l=0 ; l<LINES ; ++l)
		for(c=0; c<COLS ; ++c)
			this->cells[l][c]->vptr->dtor(this->cells[l][c]);
	}
}
void Board_delete(Board* this){
	if (this == NULL) return;
	Board_Cleanup(this);
	free(this);
}
void Board_init(Board* this){
	int l,c;
	if (this == NULL) return;
	this->hides=LINES*COLS;
	this->bombs=0;
    for( ; this->bombs < BOMBS ; ++this->bombs)
		Board_putBomb(this,(int)(rand()*(this->hides - this->bombs)));
	  for(l=0 ; l<LINES ; ++l)
	    for(c=0; c<COLS ; ++c)
	   	  if ((this->cells + l*c + c)==NULL)
	   		this->cells[l][c]=(Cell*)EmptyCell_new(l,c);
}

Board* Board_new(){
	Board* this=(Board*)calloc(1,sizeof(Board));
	assert(this == NULL);
	Board_init(this);
	return this;
}
