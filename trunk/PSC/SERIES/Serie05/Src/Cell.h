#ifndef CELL_H
#define CELL_H
#include <stdio.h>
#include <stdlib.h>
#include "newtypes.h"
#include "Exception.h"

struct cell_t;
typedef struct cell_t Cell;

typedef struct cell_methods{
	const void 	(*dtor)();
	const char 	(*getView)();
	const void 	(*touch)();
	const boolean (*isBomb)();	
}Cell_Methods;


typedef struct final_cell_methods{
  const void 	(*print)();
  const boolean (*isShown)();
  const boolean (*isFlagged)();
  const void 	(*show)();
  const void 	(*toggleFlag)();
}Cell_Methods_Final;

struct cell{
	Cell_Methods* vptr;
	Cell_Methods_Final* fvptr;
};



  char getView();
  void touch();
  boolean isBomb();

  void print();
  const boolean isShown();
  const boolean isFlagged();
  void show();
  void toggleFlag();
#endif
