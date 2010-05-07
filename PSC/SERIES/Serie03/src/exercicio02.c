#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "exercicio.02.h"

#define		MILI 	1000
#define 	MICRO	1000000
#define		NANO	1000000000

#define		LENGTH		0
#define		NBRUNS		1
#define		X1STRCAT	2
#define		X2STRCAT	3
#define 	XSTRCAT		4
#define		ASTRCAT		5
#define		STRCAT		6


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

long benchmark(char * string1, const char* string2,int nbrRun, char* (* concatenate)(char *s1, const char *s2)){
	struct timespec tstart, tfinish;
	int i;
	char tmpStr[MAX*2];
		clock_gettime(CLOCK_MONOTONIC, &tstart);
		for (i=0;i<nbrRun;++i){
			strcpy(tmpStr,string1);
			concatenate(tmpStr,string2);
		}
		clock_gettime(CLOCK_MONOTONIC, &tfinish);
	printf(">> %ld \n",(diff_time_nanos(&tstart,&tfinish)/nbrRun));
	return (diff_time_nanos(&tstart,&tfinish)/nbrRun);
}
	 
int main(){
	int i,j;
	long results[10][7];
	char string1[MAX*2]= "PSC-SV-LI31N--> ";
	char string2[MAX];
	for (i=GAP,j=0 ; i<= MAX ; i*=2,++j){
		strcpy(string2,string1);
		
		results[j][LENGTH]=i;
		results[j][NBRUNS]=(MAX/i)*32;
		
		results[j][STRCAT]=benchmark(string1,string2,(MAX/i)*32, strcat);
		
		results[j][X1STRCAT]=benchmark(string1,string2,(MAX/i)*32, x1strcat);
		
		results[j][X2STRCAT]=benchmark(string1,string2,(MAX/i)*32, x2strcat);
		
		results[j][XSTRCAT]=benchmark(string1,string2,(MAX/i)*32, xstrcat);
		
		results[j][ASTRCAT]=benchmark(string1,string2,(MAX/i)*32, astrcat);
		
		strcat(string1,string2);
	}
	
	for (i=0;i<10;++i){
		for (j=0;j<7;++j){
			printf("%ld\t",results[i][j]);
		}
			printf("\n");
	}
	
	return EXIT_SUCCESS;
}


