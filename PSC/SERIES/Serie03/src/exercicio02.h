#ifndef EXERCIO02_H
#define EXERCIO02_H
#define MAX 8192
#define RUN	64
#define GAP 16

#define		MILI 	1000
#define 	MICRO	1000000
#define		NANO	1000000000
#define		TESTS	10

#define diff_time_nanos(A,B)  ((long)((B)->tv_sec - (A)->tv_sec))*NANO + ((B)->tv_nsec - (A)->tv_nsec)
#define diff_time_micros(A,B) ((long)((B->tv_sec - A->tv_sec))*MICRO + (B->tv_nsec - A->tv_nsec)/MILI
#define diff_time_milis(A,B)  ((long)(B->tv_sec - A->tv_sec))*MILI + (B->tv_nsec - A->tv_nsec)/MICRO
#define diff_time_s(A,B)	  ((long)(B->tv_sec - A->tv_sec)) + (B->tv_nsec - A->tv_nsec)/NANO




void benchmark(char * string1, const char* string2,long * result, int line,int nbrRun, char* (* concatenate)(char *s1, const char *s2));
int timeCMP(const void* t1, const void* t2);
void printResults(long results[TESTS][RUN], int test, int run);

#endif 
