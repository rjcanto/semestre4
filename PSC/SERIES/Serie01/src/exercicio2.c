/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/
/*
 Implemente xstrcat, que será a sua versão da função strcat da biblioteca standard da linguagem C, sem
recorrer a outras funções dessa biblioteca.
     char * xstrcat(char * str1, const char * str2);
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "exercicio2.h"
/*
 * Implemente xstrcat, que será a sua versão da função strcat da 
 * biblioteca standard da linguagem C, sem recorrer a outras funções 
 * dessa biblioteca.
 * */
char * xstrcat(char * str1, const char * str2){
	int i,j;
	for(i=0;str1[i];++i);
	for(j=0,--i;str2[j];++j,++i){
		str1[i]=str2[j];
	}
	str1[i]=0;
	return str1;	
}
/*
 * Escreva um programa de teste que apresenta no standard output as 
 * linhas lidas do standard input juntas duas a duas. Na saída, cada 
 * linha será ser precedida por “nnn: ”, em que nnn é o número 
 * sequencial da linha escrita. Leia as linhas do standard input com 
 * gets, admitindo que cada uma não tem mais do que 255 caracteres.
 * 
 * É utilizado o fgets, uma vez que a documentação desaconselha o 
 * uso gets.
 * */
int main(int argc, char** argv){
	char str1[MAX_SIZE];
	char str2[STR_MAX_SIZE];
	int linenbr=0;
	for (;;){
		puts("Introduza a primeira frase :");
		if (fgets(str1,STR_MAX_SIZE,stdin) == NULL)
			return 0;
		puts("Introduza a segunda frase :");
		if (fgets(str2,MAX_SIZE,stdin) == NULL)
			return 0;
		printf("[%03d]:: %s",++linenbr,xstrcat(str1,str2));
		*str1=0;
		*str2=0; 
	}
	
	return 1;
}
