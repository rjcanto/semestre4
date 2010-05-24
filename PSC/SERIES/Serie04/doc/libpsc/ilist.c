#include "ilist.h"

void ilist_insertAfter(node_t * ref_node, node_t * new_node) {
	new_node->prev = ref_node;
	new_node->next = ref_node->next;
	ref_node->next = new_node;
	new_node->next->prev = new_node;
}

void ilist_insertBefore(node_t * ref_node, node_t * new_node) {
	new_node->next = ref_node;
	new_node->prev = ref_node->prev;
	ref_node->prev = new_node;
	new_node->prev->next = new_node;
}

void ilist_unlinkNode(node_t * node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	/* Opcionalmente:
	node->next = node->prev = node; */
}

node_t * ilist_removeFirst(node_t * snode) {
	node_t * node = ilist_first(snode);
	ilist_unlinkNode(node);
	return node;
}

node_t * ilist_removeLast(node_t * snode) {
	node_t * node = ilist_last(snode);
	ilist_unlinkNode(node);
	return node;
}

