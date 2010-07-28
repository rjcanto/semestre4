/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * ColoredPoint: versão C da classe ColoredPoint
 *
 * Uma vez que em C não existe suporte para herança utiliza-se
 * composição, integrando directamente uma instância de Point
 * como primeiro campo de ColoredPoint. Desta forma, o endereço da
 * instância de ColoredPoint coincide com o endereço da instância de
 * Point que aquela contém.
 *
 * Os "métodos" herdados e não redefinidos (getX e getY) são
 * invocados via macros.
 */

#ifndef COLORED_POINT_H
#define COLORED_POINT_H

#include "Point.h"

typedef struct rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

extern const RGB BLACK;
extern const RGB DGRAY;
extern const RGB LGRAY;
extern const RGB WHITE;
extern const RGB RED;
extern const RGB GREEN;
extern const RGB BLUE;

typedef struct colored_point {
	Point super; /* tem de ser o primeiro */
	RGB   color;
} ColoredPoint;

/* Inicialização de instâncias de ColoredPoint */
#define init_ColoredPoint(this,name) init_ColoredPoint_XY((ColoredPoint * const)(this), 0, 0, BLACK, name)
void    init_ColoredPoint_XY(ColoredPoint * this, int x, int y, RGB color, const char * name);

/* Finalização de instâncias de ColoredPoint (só finaliza a base, uma vez que não há outros recursos a gerir). */
#define cleanup_ColoredPoint(this) cleanup_Point(&(((ColoredPoint * const)(this))->super))

/* ColoredPoint_getX e ColoredPoint_getY recorrem directamente às definições da base. */
#define ColoredPoint_getX(this)  Point_getX(((const ColoredPoint * const)(this))->super)
#define ColoredPoint_getY(this)  Point_getY(((const ColoredPoint * const)(this))->super)
#define ColoredPoint_getColor(this)  (((const ColoredPoint * const)(this))->color)

#define ColoredPoint_getName(this) Point_getName(((const ColoredPoint * const)(this))->super)

#define ColoredPoint_translate(this,dx,dy)  Point_translate(((const ColoredPoint * const)(this))->super,dx,dy)
#define ColoredPoint_magnitude(this)        Point_magnitude(((const ColoredPoint * const)(this))->super)
/* ColoredPoint_print é uma redefinição. */
void    ColoredPoint_print(const ColoredPoint * this);

/* Alocação dinâmica de instâncias de ColoredPoint. */
ColoredPoint * new_ColoredPoint(const char * name);
ColoredPoint * new_ColoredPoint_XY(int x, int y, RGB color, const char * name);

/* Libertação de instâncias de ColoredPoint alocadas dinamicamente. */
void delete_ColoredPoint(ColoredPoint * this);

#endif /* COLORED_POINT_H */
