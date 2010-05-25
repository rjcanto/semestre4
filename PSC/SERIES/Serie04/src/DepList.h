#ifndef DEPLIST_H
#define DEPLIST_H
#include "LinkedList.h"

typedef	struct dependence_list_type{
	Node node;
	char* acronimo;	
}DepList;

typedef DepList DepListNode;

void DepList_init();
DepList* DepList_new();
void DepList_cleanup();
void DepList_destroyer();
void DepList_deleteNode(DepList* list);
#endif
