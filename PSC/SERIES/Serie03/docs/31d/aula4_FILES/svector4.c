#include "vector.h"

/* chamada de acesso a elemento */
void sum(Vector *v, int *dest) {
  int i, len, *p;
  *dest = 0;
  len = length_vector(v);
  p = start_vector(v);
  for (i = 0; i < len ; i++) {
    *dest += p[i];
  }
}

