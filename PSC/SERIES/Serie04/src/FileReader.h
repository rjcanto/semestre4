#ifndef FILEREADER_H
#define FILEREADER_H
#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"
#include "CDB_Builder.h"
#include "Command1.h"
#include <cdb.h>
void fileparser(char* filename);
void dblist(struct cdb* cdb, char* key, unsigned klen);
void dbReader(char* filename,char * key, void (*fx)(struct cdb* , char* , unsigned ));
void dblistAll(struct cdb* cdb, char* key, unsigned klen);
#endif
