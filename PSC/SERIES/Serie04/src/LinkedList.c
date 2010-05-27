/*
----------------------------------------------------------------------
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
----------------------------------------------------------------------
*/
#include "LinkedList.h"
/*
void init_LL(Node * head){
	head->previous = head->next = head;
}
*/
void insertAfter_LinkedList(Node* head, Node* newNode){
	newNode->next 			= head->next;
	newNode->previous 		= head;
	head->next				= newNode;
	head->next->previous 	= newNode;	
}

void unlink_LinkedList(Node * head){
	head->next->previous = head->previous;
	head->previous->next = head->next;
	head->previous=head->next=head;
}

Node * removeFirst_LinkedList(Node * head){
	Node * tmpNode = getFirst_LinkedList(head);
	unlink_LinkedList(tmpNode);
	return tmpNode;
}

