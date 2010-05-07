#include "strcatlib.h"
char * xstrcat(char * str1, const char * str2){
	char *tmp=str1;
	for(;*str1;++str1);
	for(--str1;*str2;++str2,++str1){
		*str1=*str2;
	}
	*str1=0;
	return tmp;	
}
