/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * class CDItem implements Item;
 */

#include "Item.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* A tabela de métodos virtuais de CDItem
   está definida no final deste ficheiro. */
static const ItemMethods CDItem_vtable;

/* ************************ */
/* class CDItem             */

typedef struct cd_item {
	Item super;
	const char *  title;
	const char *  artist;
	unsigned char tracks;
	unsigned int  year;
} CDItem;

/* ************************** */
/* Construção e destruição    */

static void CDItem_init(CDItem * this) {
	this->super.vptr = &CDItem_vtable;
	/* Construtor */
	this->title  = 0;
	this->artist = 0;
	this->tracks = 0;
	this->year   = 0;
}

static void CDItem_cleanup(CDItem * this) {
	/* Destrutor */
	if (this->title  != 0) free((char *)this->title );
	if (this->artist != 0) free((char *)this->artist);
}

/* ************************** */
/* Operações new e delete     */

static CDItem * new_CDItem() {
	CDItem * pobj = (CDItem *)malloc(sizeof (CDItem));
	CDItem_init(pobj);
	return pobj;
}

static void delete_CDItem(CDItem * pobj) {
	if (pobj != NULL) {
		CDItem_cleanup(pobj);
		free(pobj);
	}
}

/* ************************ */
/* Métodos da classe CDItem */

static void CDItem_destroy(CDItem * this) {
	delete_CDItem(this);
}

static int CDItem_setField(CDItem * this, const char * name, const char * value) {
	
	if (name == NULL) return -1;

	if (strcmp(name, "tracks") == 0) {
		this->tracks = value ? atoi(value) : 0;
	} else if (strcmp(name, "year") == 0) {
		this->year = value ? atoi(value) : 0;
	} else {
		char * * field = NULL;

		if (strcmp(name, "title" ) == 0) field = (char * *)&(this->title);
		else
		if (strcmp(name, "artist") == 0) field = (char * *)&(this->artist);
		
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

static size_t CDItem_toString(CDItem * this, char * buffer, size_t max_size) {
	size_t len = 50 + (this->title ? strlen(this->title) : 0) + (this->artist ? strlen(this->artist) : 0) + 2 + 4;
	if (max_size >= len) {
		sprintf(buffer, "(CD | title: \"%s\" | artist: \"%s\" | tracks: %u | year: %u)", 
			this->title  ? this->title  : "",
			this->artist ? this->artist : "",
			this->tracks & 0x3F,
			this->year & 0x1FFF);
	}
	return len;
}

/* ***************************** */
/* Tabela de métodos de CDItem */

static const ItemMethods CDItem_vtable = {
	(Item_destroy) CDItem_destroy,
	(Item_setField)CDItem_setField,
	(Item_toString)CDItem_toString
};

/* ***************************** */
/* Função criadora de CDItems  */

Item * createItem(void) { return (Item *)new_CDItem(); }
