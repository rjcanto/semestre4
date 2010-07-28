/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * interface Item;
 */

#ifndef ITEM_H
#define ITEM_H

#include <stddef.h>

struct item;
typedef struct item Item;

struct item_methods;
typedef struct item_methods ItemMethods;

/* Assinaturas dos métodos da interface Item.

   Utilizam-se typedefs para facilitar casts de ponteiros para função
   nas definições das tabelas de métodos das classes que implementam
   Item. Nessas classes, as assinaturas dos métodos são compatíveis 
   com estas, mas o tipo do ponteiro this será distinto. */
typedef	void   (*Item_destroy)       (Item * this);
typedef	int    (*Item_setField)      (Item * this, const char * name, const char * value);
typedef	size_t (*Item_toString)(const Item * this, char * buffer, size_t max_size);

/* *************************** */
/* interface Item              */

struct item_methods {
	const Item_destroy  destroy;
	const Item_setField setField;
	const Item_toString toString;
};

struct item {
	const ItemMethods * vptr;
};

/* *************************** */

/* Assinatura da função a exportar por cada bibloteca de carregamento
   dinâmico que forneça uma implementação da interface Item. */
typedef Item * (*CreateItemFunction)(void);

#endif /* ITEM_H */
