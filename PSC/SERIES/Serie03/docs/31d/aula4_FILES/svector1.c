#include "vector.h"

/* versão base */
void sum(Vector *v, int *dest) {
  int i;
  *dest = 0;
  for (i = 0; i < length_vector(v); i++) {
    int val;
    elem_vector(v, i, &val);
    *dest += val;
  }
}

