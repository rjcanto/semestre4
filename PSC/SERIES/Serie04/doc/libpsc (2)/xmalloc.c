/*
   Instituto Superior de Engenharia de Lisboa

   Engenharia Informática e de Computadores
      Programação em Sistemas Computacionais

   João Trindade
   Novembro de 2009
*/

#include "dlist.h"

#ifdef STDMALLOC
#undef STDMALLOC
#endif 
#include "xmalloc.h"

/* Dimensao do espaco a gerir dinamicamente. */
#define SPACE_SIZE 10*1024*1024

/* A dimensao realmente ocupada por um bloco. */
#define BLOCKSZ(size) (sizeof(unsigned int) + (size))

/* Garantir que qualquer bloco tem espaco para um
   dnode_t e que a sua dimensao e' multipla de 4. */
#define ALIGNSZ(size) \
	(((size) < sizeof (dnode_t)) ? \
		sizeof (dnode_t) :	\
		(((size) & 3) ? (((size) | 3) + 1) : (size)))

typedef unsigned char byte;

/* Espaco gerido dinamicamente entre space e space_end */
static byte space[SPACE_SIZE];
static byte * const space_end = space + sizeof space;

/* Fim da zona dividida em blocos e início da zona livre */
static byte * lim = space;
/* Lista de blocos livres (devolvidos por xfree) */
static dnode_t free_list = { &free_list, &free_list };

/* Campos de um bloco de memória:
   quando em uso é visto como [ size | space ...        ]
   quando livre  é visto como [ size | node | space ... ] */
typedef struct memblock {
	unsigned int size;
	dnode_t node;
} memblock_t;

/* First-fit: encontrar o primeiro bloco da lista livre com
              dimensão maior ou igual ao que é pedido. */
static memblock_t * find_free(unsigned int size) {
	dnode_t * p;
	for (p = free_list.next; p != &free_list; p = p->next) {
		memblock_t * pmb = container_of(p, memblock_t, node);
		if (pmb->size >= size) return pmb;
	} 
	return 0;
}

void * xmalloc(unsigned int size) {
	memblock_t * pmb;
	size = ALIGNSZ(size);
	pmb = find_free(size);
	if (pmb) {
		if (BLOCKSZ(pmb->size) >= BLOCKSZ(0) + BLOCKSZ(size)) {
			/* O bloco encontrado pode ser partido em 2. */
			/* O espaco para o bloco novo e' retirado do fim
			   do bloco encontrado, que se mantem na lista. */
			memblock_t * pnmb = (memblock_t*)((((char*)&(pmb->node)) + pmb->size) - BLOCKSZ(size));
			pnmb->size = size;
			pmb->size -= BLOCKSZ(size);
			return &(pnmb->node);
		} else {
			/* O bloco tem dimensao 'a justa para o pedido. */
			dlist_unlinkNode(&(pmb->node));
			return &(pmb->node);
		}
	} else {
		/* E' necessario consumir espaco adicional. */
		if (lim + BLOCKSZ(size) <= space_end) {
			/* Ainda existe espaco disponivel. */
			pmb = (memblock_t *)lim;
			lim += BLOCKSZ(size);
			pmb->size = size;
			return &(pmb->node);
		} else {
			/* Ja' nao ha' espaco adicional. Numa implementacao 
				realista de malloc, seria aqui usado o system call
				sbrk ou mmap2 para obter mais. */
			return 0;
		}
	}
}

void xfree(void * ptr) {
	dlist_insertFirst(&free_list, (dnode_t *)ptr);
}
