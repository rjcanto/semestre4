#include <stdio.h>

#define PRINT_ARRAY(A,B,C) {int i;for(i=0;i<C;++i){printf(B,*(A+i));};}


int main() {
	char *t = "ISEL";
	int a[]= {20,10,5,7,9};
	PRINT_ARRAY(t,"%c",4);
	PRINT_ARRAY(a,"%d,",5);
return 0;
} /* output: ISEL20,10,5,7,9 */
