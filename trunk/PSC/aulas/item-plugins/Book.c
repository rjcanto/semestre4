/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * class BookItem implements Item;
 */

#include "Item.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* A tabela de métodos virtuais de BookItem
   está definida no final deste ficheiro. */
static const ItemMethods BookItem_vtable;

/* ************************** */
/* class BookItem             */

typedef struct book_item {
	Item super;
	const char * title;
	const char * author;
	unsigned int year;
} BookItem;

/* ************************** */
/* Construção e destruição    */

static void BookItem_init(BookItem * this) {
	this->super.vptr = &BookItem_vtable;
	/* Construtor */
	this->title  = 0;
	this->author = 0;
	this->year   = 0;
}

static void BookItem_cleanup(BookItem * this) {
	/* Destrutor */
	if (this->title  != 0) free((char *)this->title );
	if (this->author != 0) free((char *)this->author);
}

/* ************************** */
/* Operações new e delete     */

static BookItem * new_BookItem() {
	BookItem * pobj = (BookItem *)malloc(sizeof (BookItem));
	BookItem_init(pobj);
	return pobj;
}

static void delete_BookItem(BookItem * pobj) {
	if (pobj != NULL) {
		BookItem_cleanup(pobj);
		free(pobj);
	}
}

/* ************************** */
/* Métodos da classe BookItem */

static void BookItem_destroy(BookItem * this) {
	delete_BookItem(this);
}

static int BookItem_setField(BookItem * this, const char * name, const char * value) {

	if (name == NULL) return -1;

	if (strcmp(name, "year") == 0) {
		this->year = value ? atoi(value) : 0;
	} else {
		char * * field = NULL;

		if (strcmp(name, "title" ) == 0) field = (char * *)&(this->title );
		else
		if (strcmp(name, "author") == 0) field = (char * *)&(this->author);
		
		if (field == NULL) return -1;
		
		if (*field != NULL) {
			free(*field);
			*field = NULL;
		}
		
		if (value != NULL) {
			*field = (char *)malloc(strlen(value) + 1);
			strcpy(*field, value);
		}
	}

	return 0;
}

static size_t BookItem_toString(BookItem * this, char * buffer, size_t max_size) {
	size_t len = 41 + (this->title ? strlen(this->title) : 0) + (this->author ? strlen(this->author) : 0) + 4;
	if (max_size >= len) {
		sprintf(buffer, "(BOOK | title: \"%s\" | author: \"%s\" | year: %u)", 
			this->title  ? this->title  : "",
			this->author ? this->author : "",
			this->year & 0x1FFF);
	}
	return len;
}

/* ***************************** */
/* Tabela de métodos de BookItem */

static const ItemMethods BookItem_vtable = {
	(Item_destroy) BookItem_destroy,
	(Item_setField)BookItem_setField,
	(Item_toString)BookItem_toString
};

/* ***************************** */
/* Função criadora de BookItems  */

Item * createItem(void) { return (Item *)new_BookItem(); }
