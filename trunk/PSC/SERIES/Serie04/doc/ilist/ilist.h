#ifndef ILIST_H
#define ILIST_H

#define offsetof(FIELD,STRUCT) \
	((size_t)(&(((STRUCT*)0)->FIELD)))

#define node2ptr(PTR,FIELD,STRUCT) \
	(STRUCT*)((((char*)(PTR))-offsetof(FIELD,STRUCT)))

struct node {
	struct node * prev;
	struct node * next;
};

typedef struct node node_t;

void ilist_init(node_t * snode);
int ilist_isEmpty(node_t * snode);
node_t * ilist_first(node_t * snode);
node_t * ilist_last(node_t * snode);
void ilist_insertAfter(node_t * ref_node, node_t * new_node);
void ilist_insertBefore(node_t * ref_node, node_t * new_node);
void ilist_insertFirst(node_t * snode, node_t * new_node);
void ilist_insertLast(node_t * snode, node_t * new_node);
void ilist_unlinkNode(node_t * node);
node_t * ilist_removeFirst(node_t * snode);
node_t * ilist_removeLast(node_t * snode);

#endif
