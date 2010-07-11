#include "Board.h"

#include <time.h>


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
				  this->cells[l][c]=(Cell*)BombCell_new(this);
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
boolean Board_isValid(Board* this, int l, int c){return ( l >= 0 && l < LINES && c >=0 &&  c < COLS)?true:false;}
boolean Board_isSolved(Board* this){return this->hides == this->bombs?true:false;}
boolean Board_isBomb(Board* this, int l, int c){
	return (Board_isValid(this, l, c) && this->cells[l][c]->vptr->isBomb(this->cells[l][c]))?true:false;
}

/*
 * Métodos Públicos
 * */
void Board_print(Board* this){
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
void Board_touch(Board* this, int l, int c){
	if (Board_isValid(this, l, c)){
		Cell* cel = this->cells[l][c];
		if (Cell_isShown(cel) || Cell_isFlagged(cel)){ return;}
		cel->vptr->touch(cel);
		--(this->hides);
	}
}
void Board_showAll(Board* this){
	int l,c;
	for (l=0;l< LINES;++l){
		for(c=0;c< COLS;++c){
			Cell_show(this->cells[l][c]);
		}
	}
	this->hides=0;
}
void Board_flag(Board* this, int l, int c){
	if (Board_isValid(this,l,c)){
		Cell* cel = this->cells[l][c];
		if (Cell_isShown(cel)) return;
		Cell_toggleFlag(cel);
		if (Cell_isFlagged(cel)){(this->bombs)--;(this->hides)--;}
		else{(this->bombs)++;(this->hides)++;}
	}
}

/*
 * (Des)Construtores e (Des)Iniciadores
 * */
static void Board_delete_array(Board* this){
	int l,c;
	for(l=0 ; l<LINES ; ++l){
		for(c=0; c<COLS ; ++c)
			this->cells[l][c]->vptr->dtor(this->cells[l][c]);
	
	}
}
void Board_Cleanup(Board* this){
	if (this == NULL){ 
		return;
	}else{
		Board_delete_array(this);
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
				this->cells[l][c]=(Cell*)EmptyCell_new(this,l,c);
			}
	}

}

Board* Board_new(){
	Board* this=(Board*)calloc(1,sizeof(Board));
	assert(this == NULL);
	Board_init(this);
	return this;
}
