#ifndef COMMAND_H
#define COMMAND_H
#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"

#include <cdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <cdb.h>

typedef struct met_com {
	void (*dtor)(void*);
	void (*createDB)(void*);
	void (*destroyDB)(void*);
	void (*insertDB)(void*,void*);
	void (*lineParser)(char*);
	void (*execute)(void*, char*);
	char* 	descricao;	
	char 	opcao;	
} Command_Methods;


typedef struct comando{
	const Command_Methods* vptr;
} Command;

unsigned short twoByte2UnsignedShort(char** twobyte);
byte*  CDB_field_equalize(char** field, char* value);
void unsignedShort2TwoBytes(char* dest, const unsigned short ush);
void Command_dblist(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*));
void Command_insert_CDB(void * this,struct cdb_make* cdbm,  void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF *,void* ));
void Command_dbReader(char* filename,char * key, void (*fx)(struct cdb* , char* , unsigned, void (*parser)(char*) ), void (*parser)(char*) );
void Command_dblistAll(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*) );


#endif
