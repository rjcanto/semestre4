#include "Cell.h"

/*Métodos Abstractos*/
char Cell_getView(Cell* this){
	puts ("Method not yet implemented."); return 0;
}
void Cell_touch(Cell* this){
	puts("Method not yet implemented.");
}
boolean Cell_isBomb(Cell* this){return false;}



/*Métodos Final que não poderão ser redefinidos*/
void Cell_print(Cell* this){
	printf("%c",(this->stat == VIEW)? this->vptr->getView(this): this->stat);
}
void Cell_show(Cell* this){this->stat = VIEW;}
void Cell_toggleFlag(Cell* this){
	if ( this->stat == FLAG ) this->stat = NONE;
	else
	if ( this->stat == NONE ) this->stat = FLAG;
}

/*(Des)Inicializador e Tabelas de Métodos virtuais*/
void Cell_cleanup(Cell* this){
	if (this == NULL) return;
	this->vptr = NULL;
	/*this->fvptr = NULL;*/
	this->stat = 0;
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
void Cell_init(Cell* this){
	if (this == NULL) return;
	this->vptr  = &cell_vtable;
	/*this->fvptr = &cell_fvtable;*/
	this->stat = NONE;
}
