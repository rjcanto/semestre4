#include "DepList.h"
Node* DepList_new(){
	Node* head=(Node*)malloc(sizeof(Node));
	init_LinkedList(head);
	return head;
}

void DepList_cleanup(Node* head){
	if(head == NULL) return;
	
	while(!isEmpty_LinkedList(head)){
		DepListNode_cleanup((DepListNode*)(head->next));		
	}	
	head=NULL;
}

void DepList_destroyer(Node* head){
	if(head == NULL) return ;
	DepList_cleanup(head);
	free(head);
}

void DepList_toString(Node* head){
	Node* cur=head;
	while (cur->next != head){		
		printf("[X]--> %s\n", ((DepListNode*)(cur->next))->acronimo);
		cur=cur->next;
	}	
}
/*Depende List Nodes*/
void DepListNode_init(Node* head, DepListNode* depnode, char* acronimo){
	insertBefore_LinkedList(head,(Node*)depnode);
	if (acronimo != NULL){
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
	free((DepListNode*)removeLast_LinkedList(&(this->node)));
}
void DepListNode_cleanup(DepListNode* this){
	if (this == NULL) return;
	
	if (this->acronimo != NULL){
		free(this->acronimo);
		this->acronimo=NULL;
	}	
	DepListNode_deleteNode(this);
}

void DepListNode_destroyer(DepListNode* this){
	if (this == NULL) return;
	DepListNode_cleanup(this);
	free(this);	
}

/*
int main(){
	Node* deplist = DepList_new();
	
	
	DepListNode_new(deplist,"AAA");
	DepListNode_new(deplist,"BBB");
	DepListNode_new(deplist,"CCC");
	DepListNode_new(deplist,"DDD");
	
	DepList_toString(deplist);
	
	DepList_destroyer(deplist);
	
	assert(isEmpty_LinkedList(deplist));
	return 0;
}
*/
