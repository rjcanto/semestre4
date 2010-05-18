#include <stdio.h>
#include <string.h>
#include "ilist.h"

typedef struct int_node {
	int value;
	node_t node;
} IntNode;

typedef struct reserva {
	unsigned int num;
	node_t node;
	char turma[6];
} Reserva;

extern IntNode in1, in2, in3, in4;
node_t intList =    { &(in4.node), &(in1.node) };
IntNode in4 = { 31, { &(in3.node), &intList    } };
IntNode in3 = { -5, { &(in2.node), &(in4.node) } };
IntNode in2 = { 11, { &(in1.node), &(in3.node) } };
IntNode in1 = {  2, { &intList,    &(in2.node) } };

extern Reserva r1, r2, r3;
node_t reservas =     { &(r3.node), &(r1.node) };
Reserva r1 = { 19723, { &reservas,  &(r2.node) }, "LI31N" };
Reserva r2 = { 21023, { &(r1.node), &(r3.node) }, "LI31N" };
Reserva r3 = { 20123, { &(r2.node), &reservas  }, "LI31D" };

int main() {
	node_t * pn;

	IntNode in;
	Reserva r;

	in.value = 555;
	ilist_insertLast(&intList, &(in.node));

	r.num = 19923;
	strcpy(r.turma, "LT41N");
	ilist_insertLast(&reservas, &(r.node));

	printf("\n-- Printing intList --\n");
	for (pn = intList.next; pn != &intList; pn = pn->next) {
		IntNode * pin = node2ptr(pn, node, IntNode);
		printf("%d\n", pin->value);
	}

	printf("\n-- Printing reservas --\n");
	for (pn = reservas.next; pn != &reservas; pn = pn->next) {
		Reserva * pr = node2ptr(pn, node, Reserva);
		printf("%5d : %s\n", pr->num, pr->turma);
	}

	putchar('\n');
	return 0;
}

