#ifndef _EXERCIO02_H
#define _EXERCIO02_H
#define MAX 8192
#define RUN	64
#define GAP 16
#include "strcatlib.h"
struct timespec tsTimerBeg;
struct timespec tsTimerEnd;

long benchmark(char * string1, const char* string2,int nbrRun, char* (* concatenate)(char *s1, const char *s2));

#endif 
