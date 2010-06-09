#include "FileReader.h"
#define BUFFER_SIZE 100

void fileparserUni(char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}
	
	Command1_createDB();
	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		/*Aloc de Unidade Curricular*/
		unicurr = UniCurr_new_fromString(buffer,delimiter);
		Command1_insert_UniCurr_CDB_by_acronimo(unicurr);
		/*Free de Unidade Curricular*/
		UniCurr_destroy(unicurr);
		unicurr=NULL;
	}
	Command1_destroyDB();
	fclose(fp);

}


void fileparser(char* filename){
	FILE* fp= fopen(filename, "rb");
	Teacher * teacher;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}
	
	Command3_createDB();
	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {

		teacher = Teacher_new_fromString(buffer,delimiter);
		Command3_insert_CDB_by_mec_number(teacher);

		Teacher_destroy(teacher);
		teacher=NULL;
	}
	Command3_destroyDB();
	fclose(fp);

}
