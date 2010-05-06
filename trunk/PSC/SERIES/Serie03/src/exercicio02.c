#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "exercicio.02.h"
int main(){

	int i,j;
	long timeBeg,timeEnd, result;
	char string1[8192];
	char string2[16];
	timeBeg=clock_gettime(CLOCK_MONOTONIC,&tsTimerBeg);
	sleep(2);
	printf("\n");

	timeEnd=clock_gettime(CLOCK_MONOTONIC,&tsTimerEnd);

	result=(timeEnd-timeBeg);
	printf("tamanho da str1: %d\n", strlen(string1));
	printf("tempo: %ld\n", timeBeg);
	return EXIT_SUCCESS;
}


