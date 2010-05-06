#include <stdio.h>
#include "timer.h"
#include "vector.h"

#define MAX (8*1024)
#define RUNS 32

void sum(Vector *v, int *res);

int main() {
  Vector v; int elems[MAX];
  long tm; int res, r;
  init_vector(&v,8*1024,elems);
  for(r=0 ; r<RUNS ; ++r) {
    start_timer();
    sum(&v,&res);
    tm=get_microtime();
    printf("sum=%d em %ld msecs.\n",
           res,tm);
  }
  return 0;
}
