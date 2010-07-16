#ifndef CELL_H
#define CELL_H
#include "newtypes.h"

struct cell_t;
typedef struct cell_t Cell;
enum status {NONE='*', FLAG='X', VIEW=' '};
typedef enum status Stat;


typedef struct cell_methods{
	void 	(*dtor)(Cell*);
	char 	(*getView)(Cell*);
	void 	(*touch)(Cell*);
	boolean (*isBomb)(Cell*);	
}Cell_Methods;


typedef struct final_cell_methods{
  const void 	(*print)(Cell*);
  const void 	(*show)(Cell*);
  const void 	(*toggleFlag)(Cell*);
}Cell_Methods_Final;

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
	void Cell_touch(Cell*);
	boolean Cell_isBomb(Cell*);


	void Cell_print(Cell*);
	void Cell_show(Cell*);
	void Cell_toggleFlag(Cell*);
  
	void Cell_init(Cell* this,char t);
	void Cell_cleanup(Cell* this);
#endif
