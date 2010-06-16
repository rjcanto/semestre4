#include "FileReader.h"
#define BUFFER_SIZE 100

void fileparserUni(char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	Command1* c1 = Command1_ctor();
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}
	
	
	c1->vptr->createDB(c1);
	
	/*
	Command4_createDB();
	Command5_createDB();
	Command6_createDB();
	Command7_createDB();
	Command8_createDB();
	*/
	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		
		/*Aloc de Unidade Curricular*/
		unicurr = UniCurr_new_fromString(buffer,delimiter);
		c1->vptr->insertDB(c1,unicurr);
		/*
		Command4_insert_CDB(unicurr);
		Command5_insert_CDB(unicurr);
		Command6_insert_CDB(unicurr);
		Command7_insert_CDB(unicurr);
		Command8_insert_CDB(unicurr);
		*/
		/*Free de Unidade Curricular*/
		UniCurr_destroy(unicurr);
		unicurr=NULL;
	}
	c1->vptr->destroyDB(c1);
	Command1_dtor(c1);
	
	/*
	Command4_destroyDB();
	Command5_destroyDB();
	Command6_destroyDB();
	Command7_destroyDB();
	Command8_destroyDB();
	*/
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
		Command3_insert_CDB(teacher);

		Teacher_destroy(teacher);
		teacher=NULL;
	}
	Command3_destroyDB();
	fclose(fp);

}
