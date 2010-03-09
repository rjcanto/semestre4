/*
Turma: 	LI31N
Nome: 	Nuno Cancelo
Numero: 31401
*/
#ifndef _SERIE01_EX01
#define _SERIE01_EX01

#include "serie01.h"
#define UNSUPPORTEDBYTESIZE 1
#define ZEROBYTESIZE 0
unsigned long int max_value(long int bytes);
long getValue(char* val);
void showSyntax(char * program);
void showError(char * program,unsigned int error_code);
unsigned int isNotValidByte(char* program, long int val);
#endif
