#include "ilist.h"

void ilist_init(node_t * snode) {
	snode->next = snode->prev = snode;
}

int ilist_isEmpty(node_t * snode) {
	return snode->next == snode;
}

node_t * ilist_first(node_t * snode) {
	return snode->next;
	/* Alternativa:
	return ilist_isEmpty(snode) ? NULL : snode->next; */
}

node_t * ilist_last(node_t * snode) {
	return snode->prev;
	/* Alternativa:
	return ilist_isEmpty(snode) ? NULL : snode->prev; */
}

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

void ilist_insertFirst(node_t * snode, node_t * new_node) {
	ilist_insertAfter(snode, new_node);
}

void ilist_insertLast(node_t * snode, node_t * new_node) {
	ilist_insertBefore(snode, new_node);
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

