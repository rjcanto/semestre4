#ifndef CELL_H
#define CELL_H
#include <stdio.h>
#include <stdlib.h>
#include "newtypes.h"
#include "Exception.h"
#include "BoardInterface.h"

#define CELL_VOID_CAST    void (*)(Cell*)
#define CELL_BOOLEAN_CAST boolean (*)(Cell*)
#define CELL_CHAR_CAST	char 	(*)(Cell*)



struct cell_t;
typedef struct cell_t Cell;
enum status {NONE='*', FLAG='X', VIEW=' '};
typedef enum status Stat;

#define CELL_ISSHOWN(T)		((T)->stat == VIEW)
#define CELL_ISFLAGGED(T)	((T)->stat == FLAG)


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
	Board*	board;
	Stat stat;
};
  char Cell_getView(Cell*);
  void Cell_touch(Cell*);
  boolean Cell_isBomb(Cell*);

  extern void Cell_print(Cell*);
  extern void Cell_show(Cell*);
  extern void Cell_toggleFlag(Cell*);
  
  void Cell_init(Cell* this,Board* b);
  void Cell_cleanup(Cell* this);
#endif
