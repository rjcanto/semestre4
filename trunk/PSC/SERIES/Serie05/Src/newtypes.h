#ifndef NEWTYPES_H
#define NEWTYPES_H
#include <setjmp.h>

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

enum bool {false,true};
typedef enum bool boolean;

#endif
