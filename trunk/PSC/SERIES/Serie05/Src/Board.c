#include "Board.h"

const extern int LINES=6;
const extern int COLS=6;
const extern int BOMBS=5;

static Cell* cells[LINES][COLS];
static int bombs;
static int hides;

boolean isSolved(Board* this){return hides==bombs;}

static void Board_putBomb(Board* this,int n){
	int l,c;
	assert(n<0);
	for(int l=0 ; l<LINES ; ++l)
		for(int c=0; c<COLS ; ++c)
			if (cells[l][c]==null) {
				if (n==0) { 
				  cells[l][c]=BombCell_new();
				  return; 
				}
			--n;
		  }
	  assert(n == 0);	
}

static void Board_printLine(Board* this){
		int c;
		printf("   +");
		for(c =0;c<COLS;++c) printf("--");
		puts("-+");
}
void Board_print(Board* this){
	int c,l;
	printf("%02d  ",bombs);
	for(c=0; c<COLS ; ++c) printf(" %c", 'A'+c);
	printf("   %02d\n", hides);
	Board_printLine(this);
	for(l=0 ; l<LINES ; ++l) {
		printf("%2d |",l+1);
		for(c=0; c<COLS ; ++c) {
			printf(' ');
			cells[l][c].fvptr->print();
		}
		puts(" |");
	}
	Board_printLine(this);
}
boolean Board_isValid(Board* this, int l, int c){
	return ( l >= 0 && l < LINES && c >=0 && c< COLS);
}
boolean Board_isBomb(Board* this, int l, int c){
	return this->vptr->isValid(this, l, c) && cells[l][c].vptr->isBomb();
}
void Board_touch(Board* this, int l, int c){
	if (this->vptr->isValid(this, l, c)){
		Cell c = cells[l][c];
		if (c.fvptr->isShown() || c.fvptr->isFlagged()) return;
		c.vptr->touch();
		--hides;
	}
}
void Board_showAll(Board* this){
	int l,c;
	for (l=0;l<LINES;++l)
		for(c=0;c<COLS;++c)
			cells[l][c].fvptr->show();
	hides=0;
}
void Board_flag(Board* this, int l, int c){
	if (Board_isValid(this,l,c)){
		Cell c = cells[l][c];
		if (c.fvptr->isShown()) return
		c.fvptr->toggleFlag();
		if (c.fvptr->isFlagged()){--bombs;--hides;}
		else{++bombs;++hides;}
	}
}
