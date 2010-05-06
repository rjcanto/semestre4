#include "vector.h"

/* chamar length_vector uma só vez */
void sum(Vector *v, int *dest) {
  int i, len;
  *dest = 0;
  len = length_vector(v);
  for (i = 0; i < len ; i++) {
    int val;
    elem_vector(v, i, &val);
    *dest += val;
  }
}

