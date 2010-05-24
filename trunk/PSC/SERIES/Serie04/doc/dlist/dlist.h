/*
   Instituto Superior de Engenharia de Lisboa

   Engenharia Informática e de Computadores
      Programação em Sistemas Computacionais
   Engenharia de Electrónica e Telecomunicações e de Computadores
      Programação Imperativa em C (e C++)

   João Trindade
   Maio de 2010
*/

#ifndef DLIST_H
#define DLIST_H

/* offsetof is also defined in stddef.h */
#ifndef offsetof
#define offsetof(STRUCT,FIELD) \
	((unsigned int)(&(((STRUCT*)0)->FIELD)))
#endif

/* container_of as seen on the Linux kernel source code */
#define container_of(PTR,STRUCT,FIELD) \
	(STRUCT*)((((char*)(PTR))-offsetof(STRUCT,FIELD)))

struct dnode {
	struct dnode * prev;
	struct dnode * next;
};

typedef struct dnode dnode_t;
typedef dnode_t dlist_t;

#define dlist_init(DLIST)    ((DLIST)->next = (DLIST)->prev = (DLIST))

#define dlist_isEmpty(DLIST) ((DLIST)->next == (DLIST))

#define dlist_first(DLIST)   ((DLIST)->next)
#define dlist_last(DLIST)    ((DLIST)->prev)

void dlist_insertAfter(dnode_t * ref_node, dnode_t * new_node);
void dlist_insertBefore(dnode_t * ref_node, dnode_t * new_node);

#define dlist_insertFirst(DLIST,DNODE) dlist_insertAfter(DLIST,DNODE)
#define dlist_insertLast(DLIST,DNODE) dlist_insertBefore(DLIST,DNODE)

void dlist_unlinkNode(dnode_t * node);
dnode_t * dlist_removeFirst(dlist_t * list);
dnode_t * dlist_removeLast(dlist_t * list);

#endif

