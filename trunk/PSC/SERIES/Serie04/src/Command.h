#ifndef FILEREADER_H
#define FILEREADER_H
#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"

#include <cdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <cdb.h>
unsigned short twoByte2UnsignedShort(char** twobyte);
byte*  CDB_field_equalize(char** field, char* value);
void unsignedShort2TwoBytes(char* dest, const unsigned short ush);
void Command_dblist(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*));
void Command_dbReader(char* filename,char * key, void (*fx)(struct cdb* , char* , unsigned, void (*parser)(char*) ), void (*parser)(char*) );
void Command_dblistAll(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*) );
#endif
