#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>
#include "newtypes.h"
#include "Exception.h"
#include "BoardInterface.h"


/**
 * Metodo Abstracto
 * */
char Cell_getView(Cell* this){
	puts ("Method not yet implemented."); return 0;
}
/**
 * Metodo Abstracto
 * */
void Cell_touch(Cell* this){
	puts("Method not yet implemented.");
}
/**
 * Metodos booleanos que indicam se uma celula é bomba, é visivel ou está marcada com flag
 * */
boolean Cell_isBomb(Cell* this){return false;}
boolean Cell_isShown(Cell* this){return this->stat == VIEW ? true : false;}
boolean Cell_isFlagged(Cell* this){return this->stat == FLAG ? true : false;}


/*Métodos Final que não poderão ser redefinidos*/
/**
 * Mostra uma celula
 * */
void Cell_print(Cell* this){
	printf("%c",(this->stat == VIEW)? this->vptr->getView(this): this->stat);
}
/**
 * Marca a celula como visivel
 * */
void Cell_show(Cell* this){ this->stat = VIEW;}
/**
 * (Des)Marca uma celula
 * */
void Cell_toggleFlag(Cell* this){
	if ( this->stat == FLAG ) this->stat = NONE;
	else
	if ( this->stat == NONE ) this->stat = FLAG;
}

/*(Des)Inicializador e Tabelas de Métodos virtuais*/
void Cell_cleanup(Cell* this){
	if (this == NULL) return;
	this->vptr 	= NULL;
	this->stat 	= 0;
}
static Cell_Methods cell_vtable={
	(CELL_VOID_CAST) 	Cell_cleanup,
	(CELL_CHAR_CAST)	Cell_getView,
	(CELL_VOID_CAST)	Cell_touch,
	(CELL_BOOLEAN_CAST) Cell_isBomb
};
static const Cell_Methods_Final cell_fvtable={
	(const CELL_VOID_CAST)		Cell_print,
	(const CELL_VOID_CAST)		Cell_show,
	(const CELL_VOID_CAST)		Cell_toggleFlag
};
void Cell_init(Cell* this,char t){
	if (this == NULL) return;
	this->vptr  = &cell_vtable;
	this->stat  = NONE;
	this->type 	= t;
}
