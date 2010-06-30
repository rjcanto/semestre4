#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "newtypes.h"
#include "Exception.h"
#include "Cell.h"

#define LINES 6
#define COLS  6
#define BOMBS 5


typedef struct board_t{
	Cell* cells[LINES][COLS];
	int bombs;
	int hides;
}Board;


#define Board_isSolved(T) ((T)->hides == (T)->bombs)
#define Board_isValid(T,L,C) (L >= 0 && L < LINES && C >= 0 && COLS)
#define Board_isBomb(T, L, C) ( L >= 0 && L < LINES && C >= 0 && COLS && (T)->cells[L][C]->vptr->isBomb((T)->cells[L][C]) )



/*Substituidos por macros
 * boolean isSolved(Board* this);
boolean Board_isValid(Board* this, int l, int c);
boolean Board_isBomb(Board* this, int l, int c);
*/ 
extern void Board_touch(Board* this, int l, int c);
extern void Board_showAll(Board* this);
extern void Board_flag(Board* this, int l, int c);
extern void Board_print(Board* this);

Board* Board_new();
void Board_init(Board* this);
void Board_delete(Board* this);
void Board_Cleanup(Board* this);

#endif
