/*
   Instituto Superior de Engenharia de Lisboa

   Engenharia Informática e de Computadores
      Programação em Sistemas Computacionais

   João Trindade
   Maio de 2010
*/

#ifndef XMALLOC_H
#define XMALLOC_H

#ifdef STDMALLOC
#include <stdlib.h>
#define xmalloc malloc
#define xfree free
#else
void * xmalloc(unsigned int size);
void xfree(void * ptr);
#endif

#endif

