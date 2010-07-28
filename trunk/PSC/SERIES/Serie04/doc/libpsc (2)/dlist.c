/* 
   Instituto Superior de Engenharia de Lisboa 
 
   Engenharia Informática e de Computadores 
      Programação em Sistemas Computacionais 
   Engenharia de Electrónica e Telecomunicações e de Computadores 
      Programação Imperativa em C (e C++) 
 
   João Trindade 
   Maio de 2010 
*/ 

#include "dlist.h"

void dlist_insertAfter(dnode_t * ref_node, dnode_t * new_node) {
	new_node->prev = ref_node;
	new_node->next = ref_node->next;
	ref_node->next = new_node;
	new_node->next->prev = new_node;
}

void dlist_insertBefore(dnode_t * ref_node, dnode_t * new_node) {
	new_node->next = ref_node;
	new_node->prev = ref_node->prev;
	ref_node->prev = new_node;
	new_node->prev->next = new_node;
}

void dlist_unlinkNode(dnode_t * node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = node->prev = node;
}

dnode_t * dlist_removeFirst(dlist_t * list) {
	dnode_t * node = dlist_first(list);
	dlist_unlinkNode(node);
	return node;
}

dnode_t * dlist_removeLast(dlist_t * list) {
	dnode_t * node = dlist_last(list);
	dlist_unlinkNode(node);
	return node;
}

