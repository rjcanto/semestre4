#ifndef BOARD_H
#define BOARD_H
#include "newtypes.h"
#include "Cell.h"

struct board_t;
typedef struct board_t Board;

#define LINES 6
#define COLS  6
#define BOMBS 5
struct board_t{
	Cell* cells[LINES][COLS];
	int bombs;
	int hides;
	boolean over;
};

boolean Board_isValid(Board* this, int l, int c);
boolean Board_isBomb(Board* this, int l, int c);
boolean Board_isSolved(Board* this);
boolean Board_isOver(Board* this);

void Board_touch(Board* this, int l, int c);
void Board_showAll(Board* this);
void Board_flag(Board* this, int l, int c);
void Board_print(Board* this);
void Board_import(Board* this, char* str);
char* Board_export(Board* this);

Board* Board_new();
void Board_init(Board* this);
void Board_delete(Board* this);
void Board_Cleanup(Board* this);

#endif
