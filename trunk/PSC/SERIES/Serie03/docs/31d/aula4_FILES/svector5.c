#include "vector.h"

/* acumular em variavel local  */
void sum(Vector *v, int *dest) {
  int i, len, *p, res;
  res = 0;
  len = length_vector(v);
  p = start_vector(v);
  for (i = 0; i < len ; i++) {
    res += p[i];
  }
  *dest = res;
}

