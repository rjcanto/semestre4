#include "vector.h"

/* usar ponteiros em vez de indice  */
void sum(Vector *v, int *dest) {
  int *p, res, *e;
  res = 0;
  p = start_vector(v);
  e = p+length_vector(v);
  for (; p < e ; p++) {
    res += *p;
  }
  *dest = res;
}

