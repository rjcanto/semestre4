#ifndef TEACHER_H
#define TEACHER_H

#include "Common.h"
typedef struct teacher_type{
	char *			name;
	char *			email;
	unsigned short	mec_number;
} Teacher;

Teacher* Teacher_new(char * name, char * email, unsigned short mec_number);
void Teacher_init(Teacher* this, char * name, char * email, unsigned short mec_number);
void Teacher_cleanup(Teacher* this);
void Teacher_destroy(Teacher* this);
void Teacher_toString(Teacher* this);
#endif
