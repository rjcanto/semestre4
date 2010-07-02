#include "Board.h"

#include <time.h>
static Board* cellboard;

Board* Board_getpointer(){return cellboard;}
/*
 * Métodos privados
 * */
static void Board_putBomb(Board* this,int n){
	int l,c;
	assert(n>=0);
	for(l=0 ; l<LINES ; ++l){
		for(c=0; c<COLS ; ++c){
			if (this->cells[l][c] == NULL) {
				if (n==0) { 
				  this->cells[l][c]=(Cell*)BombCell_new();
				  return; 
				}
			--n;
			}
		 }
	}
	  assert(n > 0);	
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
boolean Board_isBomb(Board* this, int l, int c){return Board_isValid(this, l, c) && this->cells[l][c]->vptr->isBomb(this->cells[l][c]);}
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
			Cell_print(this->cells[l][c]);
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
			Cell_show(this->cells[l][c]);
	this->hides=0;
}
extern void Board_flag(Board* this, int l, int c){
	if (Board_isValid(this,l,c)){
		Cell* cel = this->cells[l][c];
		if (CELL_ISSHOWN(cel)) return;
		Cell_toggleFlag(cel);
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
static void Board_init_array(Board* this){
	int l,c;
	for(l=0 ; l<LINES ; ++l){
		for(c=0; c<COLS ; ++c)
					this->cells[l][c]=NULL;
	
	}
}
void Board_init(Board* this){
	int l,c;
	unsigned int r;
	if (this == NULL) return;
	
	this->hides=LINES*COLS;
	this->bombs=0;
	
	Board_init_array(this);
	for( ; this->bombs < BOMBS ; ++this->bombs){
		r=(unsigned int)rand();	
		Board_putBomb(this,r%(this->hides - this->bombs));
		srand(time(NULL));
	}
	for(l=0 ; l<LINES ; ++l){
		for(c=0; c<COLS ; ++c)
			if ((this->cells[l][c])==NULL){
				this->cells[l][c]=(Cell*)EmptyCell_new(l,c);
			}
	}
	cellboard=this;
}

Board* Board_new(){
	Board* this=(Board*)calloc(1,sizeof(Board));
	assert(this == NULL);
	Board_init(this);
	return this;
}
