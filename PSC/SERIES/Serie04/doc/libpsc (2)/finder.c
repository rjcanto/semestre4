/*
   Instituto Superior de Engenharia de Lisboa

   Engenharia Informática e de Computadores
      Programação em Sistemas Computacionais
   Engenharia de Electrónica e Telecomunicações e de Computadores
      Programação Imperativa em C (e C++)

   João Trindade
   Maio de 2010
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#include "dlist.h"
#include "xmalloc.h"

typedef struct line_mark {
	dnode_t       node;
	unsigned long nline;
	long          pos;
} LineMark;

LineMark * newLineMark(unsigned long nline, long pos) {
	LineMark * p = (LineMark*)xmalloc(sizeof(LineMark));
	p->nline = nline;
	p->pos = pos;
	return p;
}

void deleteLineMark(LineMark * pObj) {
	xfree(pObj);
}

#define MAX_LINE 256
char line[MAX_LINE];

int getLine(char * buffer, int size, FILE * f) {
	size_t len;
	if (fgets(buffer, size, f) == NULL) return EOF;
	len = strlen(buffer);
	if (len > 0 && line[len - 1] == '\n') line[--len] = 0;
	return (int)len;
}

void showLine(FILE * f, long pos, unsigned long nline) {
	fseek(f, pos, SEEK_SET);
	getLine(line, MAX_LINE, f);
	printf("%4lu: %s\n", nline, line);
}

int main(int argc, char * argv[]) {

	FILE * f;
	unsigned long nline, count;
	long pos;
	
	dlist_t mark_list;

	if (argc != 3) {
		fprintf(stderr, "use: %s nome_de_ficheiro palavra\n", argv[0]);
		exit(1);
	}

	f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "file opening failed\n");
		exit(2);
	}

	dlist_init(&mark_list);

	/* 1: Criar lista de instâncias LineMark, em que cada nó
	      indica a posição e o número de uma linha que contém
		  a palavra procurada. */
	count = 0;
	nline = 0;
	pos = ftell(f);
	while (getLine(line, MAX_LINE, f) != EOF) {
		nline += 1;

		if (strstr(line, argv[2]) != NULL) {
			dlist_insertLast(&mark_list, &(newLineMark(nline, pos)->node));
			count += 1;
		}

		pos = ftell(f);
	}
	printf("Found %lu occurences of \"%s\" in %lu lines.\n", count, argv[2], nline);

	/* 2: Navegar nas linhas com 'p' e 'n'. */
	if (!dlist_isEmpty(&mark_list)) {
		dnode_t * pCur = pCur = &mark_list;
		int opt, isHeadChar = 1, done = 0;
		printf("n: next | p: previous | q: quit\n");
		while (!done && (opt = tolower(getchar())) != EOF) {
			/* Considerar apenas o primeiro caracter da linha. */
			if (isHeadChar) {
				isHeadChar = 0;
				switch (opt) {
					case 'p': 
						if (pCur->prev != &mark_list) {
							pCur = pCur->prev;
							showLine(f, ((LineMark*)pCur)->pos, ((LineMark*)pCur)->nline);
						}
						break;
					case 'n':
						if (pCur->next != &mark_list) {
							pCur = pCur->next;
							showLine(f, ((LineMark*)pCur)->pos, ((LineMark*)pCur)->nline);
						}
						break;
					case 'q':
						done = 1;
						break;
					default:
						printf("n: next | p: previous | q: quit\n");
						break;
				}
			} else {
				/* Ignorar os restantes caracteres ate ao fim da linha. */
				if (opt == '\n') {
					isHeadChar = 1;
				}
			}
		}

		/* 3: No final, devolver a memória ocupada pelos nós da lista. */
		while (!dlist_isEmpty(&mark_list)) {
			deleteLineMark((LineMark*)dlist_removeFirst(&mark_list));
		}
	}
	fclose(f);

	assert(dlist_isEmpty(&mark_list));

	return 0;
}
