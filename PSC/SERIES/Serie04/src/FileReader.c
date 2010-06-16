#include "FileReader.h"
#define BUFFER_SIZE 100

void fileparserUni(char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	Command1* c1 = Command1_ctor();
	Command4* c4 = Command4_ctor();
	Command5* c5 = Command5_ctor();
	Command6* c6 = Command6_ctor();
	Command7* c7 = Command7_ctor();
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}
	
	
	c1->super.vptr->createDB(c1);
	c4->super.vptr->createDB(c4);
	c5->super.vptr->createDB(c5);
	c6->super.vptr->createDB(c6);
	c7->super.vptr->createDB(c7);
	
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
		c1->super.vptr->insertDB(c1,unicurr);
		c4->super.vptr->insertDB(c4,unicurr);
		c5->super.vptr->insertDB(c5,unicurr);
		c6->super.vptr->insertDB(c6,unicurr);
		c7->super.vptr->insertDB(c7,unicurr);
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
	c1->super.vptr->destroyDB(c1);
	c4->super.vptr->destroyDB(c4);
	c5->super.vptr->destroyDB(c5);
	c6->super.vptr->destroyDB(c6);
	c7->super.vptr->destroyDB(c7);
	c1->super.vptr->dtor(c1);
	c4->super.vptr->dtor(c4);
	c5->super.vptr->dtor(c5);
	c6->super.vptr->dtor(c6);
	c7->super.vptr->dtor(c7);
	
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
	Command3* c3;
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}
	c3=Command3_ctor();
	c3->super.vptr->createDB(c3);
	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {

		teacher = Teacher_new_fromString(buffer,delimiter);
		c3->super.vptr->insertDB(c3,teacher);

		Teacher_destroy(teacher);
		teacher=NULL;
	}
	c3->super.vptr->destroyDB(c3);
	c3->super.vptr->dtor(c3);
	fclose(fp);

}
