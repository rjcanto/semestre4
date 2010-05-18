#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "exercicio02.h"
#include "strcatlib.h"

#ifdef MYCOMMENTS
	long diff_time_s(struct timespec* tstart, struct timespec* tend){
		return ((long)(tend->tv_sec - tstart->tv_sec)) + (tend->tv_nsec - tstart->tv_nsec)/NANO;
	}

	long diff_time_milis(struct timespec* tstart, struct timespec* tend){
		return ((long)(tend->tv_sec - tstart->tv_sec))*MILI + (tend->tv_nsec - tstart->tv_nsec)/MICRO;
	}

	long diff_time_micros(struct timespec* tstart, struct timespec* tend){
		return ((long)(tend->tv_sec - tstart->tv_sec))*MICRO + (tend->tv_nsec - tstart->tv_nsec)/MILI;
	}

	long diff_time_nanos(struct timespec* tstart, struct timespec* tend){
		return ((long)(tend->tv_sec - tstart->tv_sec))*NANO + (tend->tv_nsec - tstart->tv_nsec);
	}
#endif

void benchmark(char * string1, const char* string2,long * result, int line,int nbrRun, char* (* concatenate)(char *s1, const char *s2)){
	struct timespec tstart, tfinish;
	int i;
	char tmpStr[MAX*2];
		for (i=0;i<nbrRun;++i){
			strcpy(tmpStr,string1);
			clock_gettime(CLOCK_MONOTONIC, &tstart);
				concatenate(tmpStr,string2);
			clock_gettime(CLOCK_MONOTONIC, &tfinish);
			*(result + line*nbrRun + i) = (diff_time_nanos(&tstart,&tfinish));
		}
}

int timeCMP(const void* t1, const void* t2){
	return *(long*)t1 - *(long*)t2;
}

void printResults(long results[TESTS][RUN], int test, int run){
	int i,j;
		printf("Size:\tTestes --->>>\n(byte)\n");
		for (i=0;i<test;++i){
			printf("%u\t",(1<<i)*GAP);
			qsort(results[i],RUN,sizeof(long),timeCMP); 
			for (j=0;j<run;++j){
				printf("%ld\t",results[i][j]);
			}
			printf("\n");
		}
}
	 
int main(){
	int i,j;
	long strcatResult[TESTS][RUN];
	long x1strcatResult[TESTS][RUN];
	long x2strcatResult[TESTS][RUN];
	long xstrcatResult[TESTS][RUN];
	long astrcatResult[TESTS][RUN];
	
	
	char string1[MAX*2]= "PSC-SV-LI31N--> ";
	char string2[MAX];
	for (i=GAP,j=0 ; i< MAX*2 ; i*=2,++j){
		strcpy(string2,string1);
			benchmark(string1,string2,(long*)strcatResult, j, RUN, strcat);
			benchmark(string1,string2,(long*)x1strcatResult,j,RUN, x1strcat);
			benchmark(string1,string2,(long*)x2strcatResult,j,RUN, x2strcat);
			benchmark(string1,string2,(long*)xstrcatResult,j,RUN, xstrcat);
			benchmark(string1,string2,(long*)astrcatResult,j,RUN, astrcat);
		strcat(string1,string2);
	}
		printf("Teste de Performance a 'STRCAT' em Nanosegundos\n");
			printResults(strcatResult,TESTS,RUN);
		printf("Teste de Performance a 'X1STRCAT' em Nanosegundos\n");
			printResults(x1strcatResult,TESTS,RUN);
		printf("Teste de Performance a 'X2STRCAT' em Nanosegundos\n");	
			printResults(x2strcatResult,TESTS,RUN);
		printf("Teste de Performance a 'XSTRCAT' em Nanosegundos\n");
			printResults(xstrcatResult,TESTS,RUN);
		printf("Teste de Performance a 'ASTRCAT' em Nanosegundos\n");
			printResults(astrcatResult,TESTS,RUN);
		
	
	return EXIT_SUCCESS;
}


