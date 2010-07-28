/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * ColoredPoint: versão C da classe ColoredPoint
 */

#include "ColoredPoint.h"
#include <stdio.h>
#include <stdlib.h>

const RGB BLACK = {   0,   0,   0 };
const RGB DGRAY = {  84,  84,  84 };
const RGB LGRAY = { 170, 170, 170 };
const RGB WHITE = { 255, 255, 255 };
const RGB RED   = { 255,   0,   0 };
const RGB GREEN = {   0, 255,   0 };
const RGB BLUE  = {   0,   0, 255 };

static const PointMethods ColoredPoint_vtable = {
	"ColoredPoint",
	sizeof(ColoredPoint),
	(double (*)(const struct point *))Point_magnitude,
	(void   (*)(const struct point *))ColoredPoint_print
};

void init_ColoredPoint_XY(ColoredPoint * this, int x, int y, RGB color, const char * name) {
	/* Invocação explícita de função de inicialização da base. */
	init_Point_XY(&(this->super), x, y, name);
	this->super.vptr = &ColoredPoint_vtable;
	this->color = color;
}

void ColoredPoint_print(const ColoredPoint * this) {
	printf("{ name = \"%s\"; x = %d; y = %d; color = RGB:%02X%02X%02X }\n",
	       this->super.name ? this->super.name : "",
	       this->super.x, this->super.y,
		   this->color.r, this->color.g, this->color.b);
}

ColoredPoint * new_ColoredPoint(const char * name) {
	ColoredPoint * p = (ColoredPoint *)malloc(sizeof(ColoredPoint)); /* Alocação dinâmica do espaço. */
	init_ColoredPoint(p, name);                 /* Inicialização da instância.  */
	return p;
}

ColoredPoint * new_ColoredPoint_XY(int x, int y, RGB color, const char * name) {
	ColoredPoint * p = (ColoredPoint *)malloc(sizeof(ColoredPoint)); /* Alocação dinâmica do espaço. */
	init_ColoredPoint_XY(p, x, y, color, name); /* Inicialização da instância.  */
	return p;
}

void delete_ColoredPoint(ColoredPoint * this) {
	if (this != NULL) {
		cleanup_ColoredPoint(this);             /* Finalização da instância.     */
		free(this);                             /* Libertação do espaço alocado. */
	}
}
