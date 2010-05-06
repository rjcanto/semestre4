#include "strcatlib.h"
char * x1strcat(char * s1, const char * s2) {
	char *s = s1 + xstrlen(s1);
	while( xstrlen(s2) ) *(s++) = *(s2++);
	return s1;
}
