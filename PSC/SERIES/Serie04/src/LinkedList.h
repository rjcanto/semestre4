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

struct node_type{
	struct node_type* previous;
	struct node_type* next;
};
typedef struct node_type TNode;
typedef TNode Node;

#define init_LinkedList(NODE)					((NODE)->previous = (NODE)->next = (NODE))
#define isEmpty_LinkedList(NODE)				((NODE)->next == (NODE))
#define getFirst_LinkedList(NODE)				((NODE)->next)
#define getLast_LinkedList(NODE)				((NODE)->previous)


void insertAfter_LinkedList(Node * head, Node * newNode);

#define insertBefore_LinkedList(NODE_A,NODE_B) 	(insertAfter_LinkedList((NODE_A)->previous,(NODE_B)))
#define insertFirst_LinkedList(NODE_A,NODE_B)  	(insertAfter_LinkedList((NODE_A),(NODE_B)))
#define insertLast_LinkedList(NODE_A,NODE_B)	(insertAfter_LinkedList((NODE_A)->previous,(NODE_B)))

void unlink_LinkedList(Node * head);

Node * removeFirst_LinkedList(Node * head);

#define removeLast_LinkedList(NODE)			(removeFirst_LinkedList((NODE)->previous))

#endif




