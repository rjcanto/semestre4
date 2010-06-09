#ifndef TEACHER_H
#define TEACHER_H

#include "Common.h"
typedef struct teacher_type{
	char *			name;
	char *			email;
	unsigned short	mec_number;
	unsigned short 	totalsize;
} Teacher;


Teacher* Teacher_new(char * name, char * email, unsigned short mec_number);
#define Teacher_new_empty()  Teacher_new(NULL,NULL,0);
Teacher* Teacher_new_fromString(const char* line, char delimiter);

void Teacher_init(Teacher* this, char * name, char * email, unsigned short mec_number);
void Teacher_line2CDB(Teacher* this);
void Teacher_cleanup(Teacher* this);
void Teacher_destroy(Teacher* this);
void Teacher_toString(Teacher* this);
void Teacher_toString_debug(Teacher* this);
#endif
