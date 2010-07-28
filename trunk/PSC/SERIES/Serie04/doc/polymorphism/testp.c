/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * Testes simples às estruturas Point e Point3D.
 * Versão com despacho dinâmico.
 */

#include "Point.h"
#include "Point3D.h"
#include "ColoredPoint.h"
#include <stdio.h>

static void printInfo(const Point * p) {
	Point_virtual_print(p);
	printf("magnitude: %f\n", Point_virtual_magnitude(p));
}

static void printInfo3D(const Point3D * p) {
	Point3D_print(p);
	printf("magnitude: %f\n", Point3D_magnitude(p));
}

int main() {

	Point p;
	Point3D p3;
	ColoredPoint pc;

	init_Point_XY(&p, 1, 2, "p");
	printInfo(&p);

	puts("------------------------");

	Point_translate(&p, 3, 1);
	printInfo(&p);

	puts("------------------------");

	init_Point3D_XYZ(&p3, 1, 2, 3, "p3");
	printInfo(&(p3.super));  /* apresenta resultado errados, devido à falta de despacho dinâmico */
	printInfo3D(&p3);

	puts("------------------------");

	Point3D_translate(&p3, 1, 0, -1);
	printInfo(&(p3.super));  /* apresenta resultado errados, devido à falta de despacho dinâmico */
	printInfo3D(&p3);

	puts("------------------------");

	init_ColoredPoint_XY(&pc, -1, 2, RED, "pc");
	printInfo(&(pc.super));

	cleanup_ColoredPoint(&pc);
	cleanup_Point3D(&p3);
	cleanup_Point(&p);

	return 0;
}
