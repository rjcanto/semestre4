#ifndef CELL_H
#define CELL_H
#include "newtypes.h"

struct cell_t;
typedef struct cell_t Cell;
struct board_t;

enum status {NONE='*', FLAG='X', VIEW=' '};
typedef enum status Stat;


typedef struct cell_methods{
	void 	(*dtor)(Cell*);
	char 	(*getView)(Cell*);
	void 	(*touch)(Cell*,struct board_t*);
	boolean (*isBomb)(Cell*);	
}Cell_Methods;

struct cell_t{
	Cell_Methods* vptr;
	Stat stat;
	char type;
};
#define CELL_VOID_CAST    void (*)(Cell*)
#define CELL_BOOLEAN_CAST boolean (*)(Cell*)
#define CELL_CHAR_CAST	char 	(*)(Cell*)

	boolean Cell_isShown(Cell* this);
	boolean Cell_isFlagged(Cell* this);
	char Cell_getView(Cell*);
	void Cell_touch(Cell* this, struct board_t* board);
	boolean Cell_isBomb(Cell*);


	void Cell_print(Cell*);
	void Cell_show(Cell*);
	void Cell_toggleFlag(Cell*);
  
	void Cell_init(Cell* this,char t);
	void Cell_cleanup(Cell* this);
#endif
