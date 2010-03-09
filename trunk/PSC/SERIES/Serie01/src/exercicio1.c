/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/
/*
Admitindo uma arquitectura que utiliza representação de complemento para 2 para os valores inteiros com
sinal, escreva a função max_value que retorna o maior valor que pode ser armazenado no número de bytes
indicado como parâmetro. A função apenas assume que podem ser armazenados valores negativos se o
número de bytes indicado for negativo.
long int max_value(int bytes);
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "exercicio1.h"


/*
 * Retorna o maior valor que pode ser armazenado no número de bytes indicado como parâmetro.
 * */
unsigned long int max_value(long int bytes){
	long int tmp=1;
	while(bytes){
		tmp = 1+(tmp << 1);
		--bytes;
	}
	return tmp;
}
long getValue(char* val){
		return atoi(val);
}
/*
 * Mostra a sintaxe do programa.
 * */
void showSyntax(char * program){
	printf("Ajuda:\nRetorna o maior valor que pode ser armazenado no número de bytes indicado como parâmetro.\
	\nApresenta negativos se o número de bytes indicado for negativo. O valor de bytes tem que ser diferente de zero e suportado pela arquitectura.\n\n\tSintax:\n\t%s bytes\n",program);
}

/*
 * Apresenta os erros encontrados.
 * */
void showError(char * program,unsigned int error_code){
	printf("%s error:",program);
	
	switch(error_code){
			case ZEROBYTESIZE:
				printf("O valor introduzido é zero.\n\n\n");
				showSyntax(program);
				break;
			
			case UNSUPPORTEDBYTESIZE:
				printf("O valor introduzido é superior ao supportado pela a arquitectura deste computador.\n\n\n");
				showSyntax(program);
				break;
	}
}

/*
 * Verifica se o numero de bytes passado por parametro está correcto.
 * */
unsigned int isNotValidByte(char* program, long int val){
	if(val == 0 ){
		showError(program,ZEROBYTESIZE);
		return TRUE;
	}
	if(val > sizeof(long int ) && val < -1*sizeof(long int) ){
		showError(program,UNSUPPORTEDBYTESIZE);
		return TRUE;
	}
	return FALSE;
}


/*
 * Programa Principal
 * */
int main (int argc, char **argv){
	long int val;
	long int result;
	if(argc == 1){
		showSyntax(argv[0]);
		return UNSUCCESS;
	}
	val=getValue(argv[1]);
	if (isNotValidByte(argv[0],val))
			return UNSUCCESS;

	if(val>0)
		result=max_value(val*CHAR_BIT-1);
	else
		result= max_value(-1*val*CHAR_BIT-2);
		
	printf("O maior valor que pode ser armazenado em %ssigned [%ld] bytes é %lu\n",(val>0)?"un":"",(val<0)?-1*val:val,result);
		
	return SUCCESS;
}
