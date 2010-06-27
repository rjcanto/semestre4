/* ========================================================================== */
/*                                                                            */
/*   Exceptions.h                                                             */
/*   (c) 2010 		                                                          */
/*                                                                            */
/*   Description                                                              */
/*   Tratamento de Excepções "à moda do Java", uma vez que o C não forma      */
/*   "simples" de o fazer.                                                    */
/*   Base no algoritmo apresentado em:                                        */
/* http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html			  */
/* ========================================================================== */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <setjmp.h>

#define TRY       jmp_buf jmp; switch(setjmp(jmp)){case 0:
#define CATCH(E)   break;case E:
#define THROW(E)   longjmp(jmp,E)
#define TRY_END }

#define UNABLE_TO_READ_FILE_EXCEPTION 1
#define UNABLE_TO_LOAD_LIBRARY_EXCEPTION 2

#endif
