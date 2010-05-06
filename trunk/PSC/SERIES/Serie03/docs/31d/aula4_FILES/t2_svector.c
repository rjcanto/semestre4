#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "vector.h"

#define MAX (8*1024)
#define RUNS 32

void sum(Vector *v, int *res);
long times[RUNS];

int cmpTimes(const void *pa, const void *pb) 
  { return *(long*)pa - *(long*)pb; }
void sortTimes()
  { qsort(times,RUNS,sizeof(long),cmpTimes); }

int main() {
  Vector v; int elems[MAX];
  int res, r;
  init_vector(&v,8*1024,elems);
  for(r=0 ; r<RUNS ; ++r) {
    start_timer();
    sum(&v,&res);
    times[r]=get_microtime();
  }
  sortTimes();
  for(r=0 ; r<RUNS ; ++r) printf("%ld ",times[r]);
  printf("\n%ld msecs.\n",times[RUNS/4]);  
  return 0;
}
