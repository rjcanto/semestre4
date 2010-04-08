#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void destroyTree(GuessTree* node){
	if (node != NULL){
		destroyTree(node->right);
		destroyTree(node->left);
		free(node);
	}
}


GuessTree* addNode(GuessTree* this, int key,char* descriptor){
	if (this == NULL){
			this=malloc(sizeof(GuessTree));
			if (this == NULL){
				puts("Não há espaço.");
				return NULL;
			}
			this->key=0;
			this->descriptor=strcpy(malloc(strlen(descriptor)),descriptor);
			this->right=this->left=NULL;
	}else{
		if (this->key > key ){
			this->left=addNode(this->left, key,descriptor);
		}else{
			this->right=addNode(this->right, key,descriptor);
		}
	}
	return this;
}

GuessTree* removeNode(GuessTree* this, int key){
	GuessTree* TMPNode=malloc(sizeof(GuessTree));
	
	if (this == NULL){
		puts("Elemento Nulo.");
		return NULL;
	}else if( key < this->key )
		this->left = removeNode( this->left, key );
    else if( key > this->key )
        this->right = removeNode( this->right, key );
	else if( this->left && this->right ){
		TMPNode = searchMin(this->left);
		this->key = TMPNode->key;
		this->right = removeNode(this->right,this->key );
    }else{
		TMPNode = this;
		if( this->left == NULL )
			this = this->right;
		else if( this->right == NULL )
			this = this->left;
		free( TMPNode );
    }
	return this;
}

GuessTree* searchTree(GuessTree* this, int key){
	if (this == NULL) {
		return NULL;
	
	}else if (this->key < key){
		searchTree(this->left,key);
	}else if (this->key > key){
		searchTree(this->right,key);
	}else{
		return this;
	}
}

GuessTree* searchMin(GuessTree* this ){
	if( this == NULL )
		return NULL;
	else if( this->left == NULL )
		return this;
	else
		return searchMin( this->left );
}
