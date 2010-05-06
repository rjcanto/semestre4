#include "vector.h"

void elem_vector_nochk(Vector *v, int idx, int *dest) {
  *dest = v->vec[idx];
}

int elem_vector(Vector *v, int idx, int *dest) {
  if (idx<0 || idx >= v->len) return 0;
  *dest = v->vec[idx];
  return 1;
}

int length_vector(Vector *v) {
  return v->len;
}

void init_vector(Vector *v, int size, int *array) {
  /*
  int i;
  for(i=0 ; i<size ; ++i) array[i] = i;
  */
  v->vec = array;
  v->len = size;
}

int * start_vector(Vector *v) {
  return v->vec;
}
