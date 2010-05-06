#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct timespec tsTimer;


unsigned int xstrlen(const char *s) {
	const char * p=s;
	while (*(p++));
	return p-s-1;
}
char * x1strcat(char * s1, const char * s2) {
	char *s = s1 + xstrlen(s1);
	while( xstrlen(s2) ) *(s++) = *(s2++);
	return s1;
}
char * x2strcat(char *s1, const char *s2) {
	char *s = s1;
	if (*s) x2strcat(s+1,s2);
	else while( (*(s++)=*(s2++)) );
	return s1;
}
#define MAX 28
#define GAP 16



int main(){
	
	int xstrcatBenchmark[MAX];
	int astrcatBenchmark[MAX];
	int x1strcatBenchmark[MAX];
	int x2strcatBenchmark[MAX];
	int strcatBenchmark[MAX];
	
	int i,j;
	long timeBeg,timeEnd, result;
	char string1[]="\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\
	";
	char string2[]="\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890\
	abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\
	";
	timeBeg=clock_gettime(CLOCK_MONOTONIC,&tsTimer);
	for (j=0;j<MAX;++j){
	for (i = 0 ; i < MAX*GAP ; ++i){
		
		printf("%c",*(string1 + i));
	
	}
	}
	printf("\n");
	timeEnd=clock_gettime(CLOCK_MONOTONIC,&tsTimer);

	result=(timeEnd-timeBeg);
	printf("tamanho da str1: %d\n", strlen(string1));
	printf("tempo: %ld\n", timeBeg);




	return EXIT_SUCCESS;
}


