#include "strcatlib.h"
char * x2strcat(char *s1, const char *s2) {
	char *s = s1;
	if (*s) x2strcat(s+1,s2);
	else while( (*(s++)=*(s2++)) );
	return s1;
}
