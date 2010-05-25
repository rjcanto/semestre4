/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Common.h"

typedef struct node_type{
	struct Node* previous;
	struct Node* next;
} Node;

#define isEmpty_LL(NODE)				((NODE)->next == (NODE))
#define getFirst_LL(NODE)				((NODE)->next)
#define getLast_LL(NODE)				((NODE)->previous)

void init_LL(Node * head);

void insertAfter_LL(Node * head, Node * newNode);

#define insertBefore_LL(NODE_A,NODE_B) 	(insertAfter_LL((NODE_A)->previous,(NODE_B)))
#define insertFirst_LL(NODE_A,NODE_B)  	(insertAfter_LL((NODE_A),(NODE_B)))
#define insertLast_LL(NODE_A,NODE_B)	(insertAfter_LL((NODE_A)->previous,(NODE_B)))

void unlink_LinkedList(Node * head);

Node * removeFirst_LL(Node * head);

#define removeLast_LL(NODE)			(removeFirst_LL((NODE)->previous))

#endif




