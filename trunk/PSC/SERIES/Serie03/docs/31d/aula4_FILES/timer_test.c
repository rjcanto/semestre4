#include <stdio.h>
#include "timer.h"

int main() {
  long tm;
  puts("Hit enter.");
  
  start_timer();
  getchar();
  tm = get_microtime();
  
  printf("Elapsed time=%ld micro seconds.\n",tm);
  return 0;
}
