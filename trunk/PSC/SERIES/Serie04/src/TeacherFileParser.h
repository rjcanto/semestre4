/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/

#ifndef TEACHERFILEPARSER_H
#define TEACHERFILEPARSER_H
#include "Common.h"
typedef struct teacher_type{
	char *			name;
	char *			email;
	unsigned short	mec_number;
} Teacher;

typedef struct Teacher_Node_List{
	node			head;
	struct Teacher *	prof_record;
} Teacher_list;
#endif
