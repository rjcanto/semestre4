#include <malloc.h>
#include "Oper.h"

typedef struct {
  Oper super;
  Oper *sum;
  int count;
} Avg;

static char * name(Avg *this) { return "Avg"; }

static void insert(Avg *this, float val) { 
  pcall1(this->sum,insert,val);
  this->count++;
}
static float result(Avg *this) { 
  return pcall(this->sum,result) / this->count; 
}
static void reset(Avg *this) { 
  pcall(this->sum,reset);
  this->count=0; 
}
static void destroy(Avg *this) { 
  destroyOper(this->sum);
  free(this); 
}

static VtableOper vtable = { 
  (destroyFx) destroy,
  (nameFx)name, (insertFx)insert, 
  (resultFx)result, (resetFx)reset 
};

Oper * newInstance() {
  Avg * op;
  op = malloc(sizeof(Avg));
  op->super.vtbl = &vtable;
  op->sum = loadOper("Sum");
  reset(op);
  return (Oper*)op;
}

