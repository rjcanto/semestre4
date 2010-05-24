#ifndef ILIST_H
#define ILIST_H

#define offsetof(FIELD,STRUCT) \
	((unsigned int)(&(((STRUCT*)0)->FIELD)))

#define node2ptr(PTR,FIELD,STRUCT) \
	(STRUCT*)((((char*)(PTR))-offsetof(FIELD,STRUCT)))

struct node {
	struct node * prev;
	struct node * next;
};

typedef struct node node_t;

#define ilist_init(SNODE)    ((SNODE)->next = (SNODE)->prev = (SNODE))

#define ilist_isEmpty(SNODE) ((SNODE)->next == (SNODE))

#define ilist_first(SNODE)   ((SNODE)->next)
#define ilist_last(SNODE)    ((SNODE)->prev)

void ilist_insertAfter(node_t * ref_node, node_t * new_node);
void ilist_insertBefore(node_t * ref_node, node_t * new_node);

#define ilist_insertFirst(SNODE,NNODE) ilist_insertAfter(SNODE,NNODE)
#define ilist_insertLast(SNODE,NNODE) ilist_insertBefore(SNODE,NNODE);

void ilist_unlinkNode(node_t * node);
node_t * ilist_removeFirst(node_t * snode);
node_t * ilist_removeLast(node_t * snode);

#endif
