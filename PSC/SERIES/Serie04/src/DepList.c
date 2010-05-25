#include "DepList.h"
void DepList_copyNode(DepList* this,DepList* list){

}

void DepList_init(DepList* this,DepListHead* head,char* acronimo){

}

DepListNode* DepListNode_new(){
	DepListNode* thisnode = (DepListNode*)malloc(sizeof(DepListNode));
	init_LL(thisnode);
	return thisnode;	
}
{
DepList* DepList_new(char* acronimo){
	DepList* 
	
	
	

	return this;
}


void DepList_cleanup(DepList* this){
	if (this == NULL) return;
	
	while (&(this->node) != &((Node)this)) {
		DepList_deleteNode(this));
		if (this->acronimo != NULL){
			free(this->acronimo);
			this->acronimo=NULL;
		}
	}	
}



void DepList_deleteNode(DepList* this){
	Node * node = removeFirst_LL(&(this->node));
	free(node);
	node = NULL;
}
void DepList_destroyer(DepList* this){
	if (this == NULL) return;
	DepList_cleanup(this);
	free(this);	
}

