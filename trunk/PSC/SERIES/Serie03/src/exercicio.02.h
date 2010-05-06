#ifndef _EXERCIO02_H
#define _EXERCIO02_H
#define MAX 8192
#define RUN	64
#define GAP 16
struct timespec tsTimerBeg;
struct timespec tsTimerEnd;

long benchmark(char * string1, char* string2, char* (* concatenate)(char *s1, const char *s2));

#endif 
