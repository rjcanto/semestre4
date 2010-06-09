#ifndef COMMON_H
#define COMMON_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>


typedef char byte;
byte* copy_field(const byte * src, const byte * end);
byte* get_next_field(const byte * line, const char delimiter);
typedef struct cdb_line_fields{
	unsigned short int size;
	char * line;
}CDBLF;
#endif
