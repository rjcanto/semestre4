#ifndef DEPLIST_H
#define DEPLIST_H

#include "LinkedList.h"

#include "Common.h"

typedef	struct dependence_list_type{
	Node node;
	char* acronimo;	
}DepListNode;

void DepList_copyNode(DepList* this,DepList* list);
void DepList_init();
DepList* DepList_new(char* acronimo);
void DepList_cleanup();
void DepList_destroyer();
void DepList_deleteNode(DepList* list);
#endif
