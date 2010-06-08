#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"
#define BUFFER_SIZE 100

void fileparser(char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition, or disk space!\n");
			exit(2);
	}
	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		unicurr = UniCurr_new_fromString(buffer,delimiter);
		UniCurr_toString(unicurr);
		UniCurr_destroy(unicurr);
	}

	fclose(fp);
}





