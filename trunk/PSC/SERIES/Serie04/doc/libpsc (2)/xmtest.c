/*
   Instituto Superior de Engenharia de Lisboa

   Engenharia Informática e de Computadores
      Programação em Sistemas Computacionais

   João Trindade
   Novembro de 2009
*/

#include <stdio.h>
#include "xmalloc.h"

#define P(N) printf("p[" #N "] = %p\n", p[N])

int main() {
	void * p[8];
	p[0] = xmalloc(250); P(0);
	p[1] = xmalloc(1);   P(1);
	p[2] = xmalloc(14);  P(2);
	xfree(p[1]);
	p[3] = xmalloc(7);   P(3);
	p[4] = xmalloc(500); P(4);
	xfree(p[0]);
	xfree(p[3]);
	p[5] = xmalloc(257); P(5);
	p[6] = xmalloc(252); P(6);
	return 0;
}

