#include "Common.h"
char* copy_field(char * src, char * end){
	char * dst=NULL;
	if ((end - src) < 1) return NULL;
	
	dst = (char*)malloc(end - src + 1);
	strcpy(dst, src);
	return dst;
}

char* get_next_field(const char * line, const char delimiter){
	char * myline=NULL; 

	char * field=NULL;
	char * cursor=NULL;

	if (line == NULL || *line == 0 || *line == delimiter) return NULL;

	/*
	 * Copia a string de entrada para poder alterar, sem prejudicar a 
	 * original
	 * */
	myline = (char*)malloc(strlen(line)+1);
	strcpy(myline, line);
	field = myline;
	cursor	= myline; 
		
	while (*cursor && (*cursor != delimiter))
		++cursor;
	*(cursor) = '\0';
	field=copy_field(myline,cursor);
	/*
	 *Liberta o espaço ocupado anteriormente pela copia da string
	 * */ 
	free(myline);
	return field;
}
