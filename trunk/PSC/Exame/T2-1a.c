#include <stdio.h>
#define PRINT_ARRAY(A,B,C) {int d=0;for(;d<C;++d){printf (B,*(A+d));}}

int main(){
	char *t = "ISEL";
	int a[] ={20,10,5,7,9};
	PRINT_ARRAY(t,"%c",4);
	PRINT_ARRAY(a,"%d,",5);
	return 0;
}
