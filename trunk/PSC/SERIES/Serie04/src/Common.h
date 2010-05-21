/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/
#ifndef COMMON_H
#define COMMON_H

typedef 	char	byte;

typedef struct node_type{
	struct * node previous;
	struct * node next;
} node;

typedef struct teacher_type{
	char *			name;
	char *			email;
	unsigned short	mec_number;
} Teacher;

typedef struct uniCurr_type{
	char *			uniCurr;
	char *			className;
	Dep_list*		strongDep;
	Dep_list*		weakDep;
	unsigned short	mec_number:
	byte			type;
	byte			semester;	
} UC;

#endif
