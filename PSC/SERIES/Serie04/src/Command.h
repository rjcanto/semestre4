#ifndef FILEREADER_H
#define FILEREADER_H
#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"
#include "CDB_Builder.h"
#include <cdb.h>
unsigned short twoByte2UnsignedShort(char** twobyte);
void unsignedShort2TwoBytes(char* dest, const unsigned short ush);
void Command_dblist(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*));
void Command_dbReader(char* filename,char * key, void (*fx)(struct cdb* , char* , unsigned, void (*parser)(char*) ), void (*parser)(char*) );
void Command_dblistAll(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*) );
#endif
