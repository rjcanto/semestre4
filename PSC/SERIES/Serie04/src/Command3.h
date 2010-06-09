#ifndef COMMAND3_H
#define COMMAND3_H
#include "Common.h"
#include "Teacher.h"
#include "CDB_Builder.h"
#include "Command.h"
#include <cdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void Command3_createDB();
void Command3_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int));
void Command3_destroyDB();
void Command3_insert_CDB_by_mec_number(void * this);

void Command3_queryCDB1(char* key);
void Command3_parseLine(char* line);
void Command3_getLine(CDBLF * result,Teacher* this );

/*define   Command3_insert_CDB_by_mec_number(P_UC) 	Command3_insert_CDB( (P_UC) , ( (P_UC)->mec_number )  , sizeof( (P_UC)->mec_number)  , &cdb_make_add )*/
/*
#define Command1_insert_UniCurr_CDB_by_mec_number(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->mec_number ), sizeof( (P_UC)->mec_number), &cdb_make_add )
#define   Command1_insert_UniCurr_CDB_by_acronimo(P_UC) 	Command1_insert_CDB( (P_UC) , ( (P_UC)->acronimo )  , strlen( (P_UC)->acronimo)  , &cdb_make_add )
#define   Command1_insert_UniCurr_CDB_by_semestre(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->semestre )  , sizeof( (P_UC)->semestre)  , &cdb_make_add )
#define       Command1_insert_UniCurr_CDB_by_tipo(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->type )      , sizeof( (P_UC)->type)      , &cdb_make_add )
*/

#endif
