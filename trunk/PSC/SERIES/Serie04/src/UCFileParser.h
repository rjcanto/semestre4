/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/

#ifndef UCFILEPARSER_H
#define UCFILEPARSER_H
#include "Common.h"
typedef struct dep_node_list{
	node 	dep_node;
	char *	uniCurr;
} Dep_list;



typedef struct UC_Node_List{
	node		head;
	struct UC * uc_record;	
} UC_list;

#endif
