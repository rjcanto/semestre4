#include "DepList.h"
Node* DepList_new(){
	Node* head=(Node*)malloc(sizeof(Node));
	init_LinkedList(head);
	return head;
}

void DepList_cleanup(Node* head){
	if(head == NULL) return;
	
	while(!isEmpty_LinkedList(head)){
		DepListNode_destroyer(((DepListNode*)(head->next)));		
	}	
	head=NULL;
}

void DepList_destroyer(Node* head){
	if(head == NULL) return ;
	DepList_cleanup(head);
	free(head);
}



/*Depende List Nodes*/
void DepListNode_init(Node* head, DepListNode* depnode, char* acronimo){
	insertAfter_LinkedList(head,&(depnode->node));
	
	if (acronimo == NULL){
		char* ac=(char*)malloc(strlen(acronimo)+1);
		strcpy(ac,acronimo);
		depnode->acronimo=ac;
	}else{
		depnode->acronimo=NULL;
	}
}
DepListNode* DepListNode_new(Node* head, char* acronimo){
	DepListNode* thisnode = (DepListNode*)malloc(sizeof(DepListNode));
	DepListNode_init(head, thisnode, acronimo);
	return thisnode;	
}
void DepListNode_deleteNode(DepListNode* this){
	Node * node = removeFirst_LinkedList(&(this->node));
	free(node);
	node = NULL;
}
void DepListNode_cleanup(DepListNode* this){
	if (this == NULL) return;
	DepListNode_deleteNode(this);
	if (this->acronimo != NULL){
		free(this->acronimo);
		this->acronimo=NULL;
	}	
}

void DepListNode_destroyer(DepListNode* this){
	if (this == NULL) return;
	DepListNode_cleanup(this);
	free(this);	
}

