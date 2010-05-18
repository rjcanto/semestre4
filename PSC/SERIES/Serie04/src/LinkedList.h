/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node_type{
	struct * node previous;
	struct * node next;
} node;


#define isEmpty_LinkedList(NODE)				(NODE)->next == (NODE)
#define getFirst_LinkedList(NODE)				(NODE)->next
#define getLast_LinkedList(NODE)				(NODE)->previous

void init_LinkedList(node * head);

void insertAfter_LinkedList(node * head, node * newNode);

#define insertBefore_LinkedList(NODE_A,NODE_B) 	insertAfter_LinkedList((NODE_A)->previous,(NODE_B))
#define insertFirst_LinkedList(NODE_A,NODE_B)  	insertAfter_LinkedList((NODE_A),(NODE_B))
#define insertLast_LinkedList(NODE_A,NODE_B)	insertAfter_LinkedList((NODE_A)->previous,(NODE_B))

void unlink_LinkedLis(node * head);

node * removeFirst_LinkedList(node * head);

#define removeFirst_LinkedList(NODE)			removeFirst_LinkedList((NODE)->previous)




#endif




