#include <stdio.h>
#include "readline.h"

int main(){
  char line[10];
  
  printf("c:\\ %s \n",readline(line,10));
  
  return 1;
}
