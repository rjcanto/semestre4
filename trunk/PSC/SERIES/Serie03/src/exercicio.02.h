#ifndef _EXERCIO02_H
#define _EXERCIO02_H
#define MAX 8192
#define RUN	64
#define GAP 16

struct timespec tsTimerBeg;
struct timespec tsTimerEnd;

void benchmark(char * string1, const char* string2,long* result, int nbrRun, char* (* concatenate)(char *s1, const char *s2));

#endif 
