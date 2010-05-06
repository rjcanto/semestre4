#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "vector.h"

#define RUNS 64
long times[RUNS];

int cmpTimes(const void *pa, const void *pb) 
  { return *(long*)pa - *(long*)pb; }
void sortTimes()
  { qsort(times,RUNS,sizeof(long),cmpTimes); }
void printTimes(char *title) { 
  int i;
  printf("%s: ",title);
  for(i=0 ; i<RUNS ; ++i) printf("%ld ",times[i]);
  putchar('\n');
}

#define KB 1024
#define MAX (16*KB)
#define MIN (1*KB)
#define DELTA (1*KB)

Vector v;
int elems[MAX];

void sum(Vector *v, int *res);

int main() {
  int sz, run, res;
  for(sz=KB ; sz<=16*KB ; sz+=KB) {
    init_vector(&v,sz,elems);
    for(run=0 ; run<RUNS ; ++run) {
      start_timer();
		sum(&v,&res);
		times[run]=get_microtime();
    }
    sortTimes();
    printf("%dKb\t%ld\n",sz/KB,times[RUNS/4]);
  }
  return 0;
}
