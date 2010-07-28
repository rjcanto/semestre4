#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "Oper.h"

Oper * loadOper(char * opName) {
   void *h;
   Oper * (*ni)();
   Oper *op;
   char libName[64];
   
   sprintf(libName,"./%s.so",opName);
   h = dlopen(libName,RTLD_NOW);
   if (!h) return NULL;
   *(void**)&ni = dlsym(h,"newInstance");
   if (!ni) { dlclose(h); return NULL; }
   op = ni();
   op->h = h;
   return op;
}

void destroyOper(Oper *op) {
  void *h = op->h;
  pcall(op,destroy);
  dlclose(h);
}

void execOper(Oper *op, char *line) {
  float val;
  pcall(op,reset);
  while ( sscanf(line,"%f",&val)>0 ) {
    pcall1(op,insert,val);
    if ((line = strchr(line,' '))==NULL) break;
    while (*line==' ') ++line;
  }
  printf("%s = %f\n",pcall(op,name),pcall(op,result));
}
 
int main(int ac, char **av)  {
   int i, max;
   char line[256];
   Oper* *op;
   
   max = ac-1;
   op = (Oper**) malloc(sizeof(Oper*)*max);
   
   for(i=0; i<max ; ++i)
     if ((op[i] = loadOper(av[i+1]))==NULL) {
       fprintf(stderr,"Erro no operador %s\n",av[i+1]);
       max = i;
     }
   while ( fgets(line,256,stdin) && strlen(line)>1 )
     for(i=0; i<max ; ++i)
       execOper(op[i],line);
   for(i=0; i<max ; ++i) destroyOper(op[i]);
   free(op);
   return 0;
}
  
