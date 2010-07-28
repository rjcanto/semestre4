#include <malloc.h>
#include "Oper.h"

typedef struct {
  Oper super;
  float total;
} Sum;

static char * name(Sum *this) { return "Sum"; }
static void insert(Sum *this, float val) { this->total+=val; }
static float result(Sum *this) { return this->total; }
static void reset(Sum *this) { this->total=0; }
static void destroy(Sum *this) { free(this); }

static VtableOper vtable = { 
  (destroyFx) destroy,
  (nameFx)name, (insertFx)insert, 
  (resultFx)result, (resetFx)reset 
};

Oper * newInstance() {
  Sum * op;
  op = malloc(sizeof(Sum));
  op->super.vtbl = &vtable;
  op->total = 0;
  return (Oper*)op;
}



