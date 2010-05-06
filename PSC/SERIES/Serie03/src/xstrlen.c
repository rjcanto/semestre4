#include "strcatlib.h"
unsigned int xstrlen(const char *s) {
	const char * p=s;
	while (*(p++));
	return p-s-1;
}
