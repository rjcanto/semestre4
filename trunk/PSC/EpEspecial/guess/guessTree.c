#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GuessTreeNode;
typedef struct GuessTreeNode GTREE;

struct GuessTreeNode{
	int 						key;
	char						*descriptor;
	GTREE  		*ifItsTrue;
	GTREE  		*ifItsFalse;
};

void guessTreeDestroy(GTREE *node){
	if( node != NULL ){
		guessTreeDestroy( node->ifItsTrue );
		guessTreeDestroy( node->ifItsFalse );
		free( node );
	}
}

GTREE* searchGuessNode( int key,GTREE *node ){
	if( node == NULL ) return NULL;
	
	if( key < node->key ){
		return searchGuessNode( key, node->ifItsTrue );
	}else{
		if( key > node->key ){
			return searchGuessNode( key, node->ifItsFalse );
		}else{
			return node;
		}
	}
}
GTREE* addGuessNode( int key,GTREE *node ){
	if( node == NULL ){
		node = malloc( sizeof( GTREE ) );
		if( node == NULL ){
			puts( "Sem espaço na memória." );
			return NULL;
		}else{
			node->key = key;
			node->ifItsTrue = node->ifItsFalse = NULL;
		}
	}else{
		if( key < node->key ){
			node->ifItsTrue = addGuessNode( key, node->ifItsTrue );
		}else{
			if( key > node->key ){
				node->ifItsFalse = addGuessNode( key, node->ifItsFalse );
			}
		}
	}
	return node;  
}
GTREE* deleteGuessNode( int key,GTREE *node ){
	GTREE* TmpCell;

	if( node == NULL ){
		puts( "Caracteristica não encontrada" );
		return NULL;
	}else if( key < node->key ){
		node->ifItsTrue = deleteGuessNode( key, node->ifItsTrue );
	}else if( key > node->key ){
		node->ifItsFalse = deleteGuessNode( key, node->ifItsFalse );
	}else if( node->ifItsTrue && node->ifItsFalse ){
		TmpCell = sGuessMinNode( node->ifItsFalse );
		node->key = TmpCell->key;
		node->ifItsFalse = deleteGuessNode( node->key, node->ifItsFalse );
	}else{
		TmpCell = node;
		if( node->ifItsTrue == NULL ) 
			node = node->ifItsFalse;
		else if( node->ifItsFalse == NULL )
			node = node->ifItsTrue;
		free( TmpCell );
	}
	return node;
}

GTREE* sGuessMinNode(GTREE *node ){
	if( node == NULL ){
		return NULL;
	}else{
		if( node->ifItsTrue == NULL ){
			return node;
		}else{
			return sGuessMinNode(node->ifItsTrue );
		}
	}
}

