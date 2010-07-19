#include "Board.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "BombCell.h"
#include "EmptyCell.h"
/**
 * Método que coloca a bomba no tabuleiro
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
/**
 * Método que imprime uma linha do border do tabuleiro
 * */
static void Board_printLine(Board* this){
		int c;
		printf("   +");
		for(c =0;c < COLS;++c) printf("--");
		puts("-+");
}

/**
 * Métodos Booleanos que verificam se a posição é válida, o tabuleiro está resolvido,
 * se o jogo já acabou ou se uma posição é uma bomba.
 * */
boolean Board_isValid(Board* this, int l, int c){return ( l >= 0 && l < LINES && c >=0 &&  c < COLS)?true:false;}
boolean Board_isSolved(Board* this){return this->hides == this->bombs?true:false;}
boolean Board_isOver(Board* this){return this->over;}
boolean Board_isBomb(Board* this, int l, int c){
	return (Board_isValid(this, l, c) && this->cells[l][c]->vptr->isBomb(this->cells[l][c]))?true:false;
}

/**
 * Imprimem o tabuleiro no ecra
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
/**
 * Procede à modificação de uma posição
 * */
void Board_touch(Board* this, int l, int c){
	if (Board_isValid(this, l, c)){
		Cell* cel = this->cells[l][c];
		if (Cell_isShown(cel) || Cell_isFlagged(cel)){ return;}
		cel->vptr->touch(cel,this);
		--(this->hides);
	}
}
/**
 * Torna todas as posições visiveis
 * */
void Board_showAll(Board* this){
	int l,c;
	this->over = true;
	for (l=0;l< LINES;++l){
		for(c=0;c< COLS;++c){
			Cell_show(this->cells[l][c]);
		}
	}
	
}
/**
 * Procede à modificação de uma posição, marcando-a como flag
 * */
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
	this->over=false;
	
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

}

Board* Board_new(){
	Board* this=(Board*)calloc(1,sizeof(Board));
	assert(this == NULL);
	Board_init(this);
	return this;
}

/**
 * Copia o conteudo de um tabuleiro para outro.
 * Util para fazer load de um jogo
 * */
static void	Board_Copy(Board* dest, Board* src){
	int l,c;
	if(dest == NULL || src == NULL) return;
	Board_Cleanup(dest);
	Board_init_array(dest);
	dest->hides = src->hides;
	dest->bombs = src->bombs;
	for(l=0;l<LINES;++l){
		for(c=0;c<COLS;++c){
			dest->cells[l][c]=src->cells[l][c];
			dest->cells[l][c]->stat=src->cells[l][c]->stat;
		}
	}
}
/**
 * Exporta um tabuleiro no formato
 * <TYPE><STAT>
 * Aloca dinamicamente espaço para uma string com o tabuleiro.
 * quem chama a função deve libertar o espaço quando não necessitar 
 * */
char* Board_export(Board* this){
	if (this == NULL) return NULL;
	
	if (Board_isSolved(this) || Board_isOver(this)) {puts("No Game to Save!"); return NULL;}
	else{
	int i, j;
	char* return_str=(char*)calloc(LINES*COLS*2+1,sizeof(char));
	char* ret=return_str;
	
	for(i=0;i<LINES;++i){
		for(j=0;j<COLS;++j,return_str+=2){
			sprintf(return_str,"%c%c",this->cells[i][j]->type,this->cells[i][j]->stat);
		}
	}
			
	*(return_str ) = 0;
	
	return ret;
	}
}
/**
 * Contabiliza as bombas para o carregamento de um jogo gravado
 * */
static void Board_import_count(Board* this){
	int l,c;
	Cell* cel;
	for (l=0;l<LINES;++l){
		for(c=0;c<COLS;++c){
			cel=this->cells[l][c];
			if (cel->type == 'E' && Cell_isShown(cel)){
				EmptyCell_touch_count((EmptyCell*)this->cells[l][c],this);
			}
		}
	}
}
/**
 * Importa um jogo Gravado
 * */
void Board_import(Board* this, char* str){
	int cellnbr=0;
	Board savedBoard;
	if (this ==  NULL && str == NULL) {puts("No Game to Load!");return;}
	
	Board_init_array(&savedBoard);
	savedBoard.hides=LINES*COLS;
	savedBoard.bombs=0;
	savedBoard.over=false;
	for(;*str;++str,++cellnbr){
		if (*str == 'B'){
			savedBoard.cells[cellnbr/LINES][cellnbr%COLS]=(Cell*)BombCell_new();
			savedBoard.bombs++;
		}else if (*str == 'E'){
			savedBoard.cells[cellnbr/LINES][cellnbr%COLS]=(Cell*)EmptyCell_new(cellnbr/LINES,cellnbr%COLS);	
			
		}else{
			puts("Invalid Board load.");
			Board_Cleanup(&savedBoard);
			return;
		}
		str++;	
		savedBoard.cells[cellnbr/LINES][cellnbr%COLS]->stat=*str;
	}
	Board_Copy(this,&savedBoard);
	
	Board_import_count(&savedBoard);
	
}
