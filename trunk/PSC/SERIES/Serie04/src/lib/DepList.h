#ifndef DEPLIST_H
#define DEPLIST_H
#include "Common.h"
#include "LinkedList.h"



typedef	struct dependence_list_type{
	Node node;
	char* acronimo;	
}DepListNode;

Node* DepList_new();
void DepList_cleanup(Node* head);
void DepList_destroyer(Node* head);

void DepListNode_init(Node* head, DepListNode* depnode, char* acronimo);
DepListNode* DepListNode_new(Node* head, char* acronimo);
void DepListNode_deleteNode(DepListNode* this);
void DepListNode_cleanup(DepListNode* this);
void DepListNode_destroyer(DepListNode* this);
#endif
