#include "Common.h"

/**
 * Devolve um ponteiro com o conteudo do campo que começa em src e acaba
 * em end.
 * 
 * */
byte* copy_field(const byte * src, const byte * end){
	byte * dst=NULL;

	if ((end - src) < 1) return NULL;
	dst = (char*)malloc(end - src + 1);
	strcpy(dst, src);
	return dst;
}
/**
 * Devolve um ponteiro para com o conteudo do proximo campo da linha. 
 * Quem chama a função deve libertar o espaço alocado por esta função.
 * */
byte* get_next_field(const byte * line, const char delimiter){
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
