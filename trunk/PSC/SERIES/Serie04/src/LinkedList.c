/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/
#include "LinkedList.h"

#define isEmpty_LinkedList(NODE)				(NODE)->next == (NODE)
#define getFirst_LinkedList(NODE)				(NODE)->next
#define getLast_LinkedList(NODE)				(NODE)->previous
#define insertBefore_LinkedList(NODE_A,NODE_B) 	insertAfter_LinkedList((NODE_A)->previous,(NODE_B))
#define insertFirst_LinkedList(NODE_A,NODE_B)  	insertAfter_LinkedList((NODE_A),(NODE_B))
#define insertLast_LinkedList(NODE_A,NODE_B)	insertAfter_LinkedList((NODE_A)->previous,(NODE_B))
#define removeFirst_LinkedList(NODE)			removeFirst_LinkedList((NODE)->previous)


void init_LinkedList(node * head){
	head->previous = head->next = head;
}

void insertAfter_LinkedList(node * head, node * newNode){
	newNode->next 			= head->next;
	newNode->previous 		= head;
	head->next				= newNode;
	head->next->previous 	= newNode;	
}

void unlink_LinkedLis(node * head){
	head->next->previous = head->previous;
	head->previous->next = head->next;
	head->previous=head->next=head;
}

node * removeFirst_LinkedList(node * head){
	node * tmpNode = getFirst_LinkedList(head);
	unlink_LinkedLis(tmpNode);
	return tmpNode;
}

