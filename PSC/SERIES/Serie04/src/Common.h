#ifndef COMMON_H
#define COMMON_H
#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
typedef char byte;
char* copy_field(char * src, char * end);
char* get_next_field(const char * line, const char delimiter);

#endif
