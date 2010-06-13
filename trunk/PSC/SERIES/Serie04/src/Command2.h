#ifndef COMMAND2_H
#define COMMAND_H
#include "Command.h"
#include "Command1.h"
#include "Command3.h"
void Command2_createDB();
void Command2_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF *,void* ));
void Command2_destroyDB();

void Command2_getLine(CDBLF * result,void* t );
void Command2_queryCDB1();

#define   Command2_insert_UniCurr_CDB_by_acronimo(P_UC) 	Command2_insert_CDB( (P_UC) , ( (P_UC)->acronimo )  , strlen( (P_UC)->acronimo)  , &cdb_make_add,Command2_getLine )
/*
#define Command2_insert_UniCurr_CDB_by_mec_number(P_UC) 	Command2_insert_CDB( (P_UC) ,&( (P_UC)->mec_number ), sizeof( (P_UC)->mec_number), &cdb_make_add )
#define   Command2_insert_UniCurr_CDB_by_acronimo(P_UC) 	Command2_insert_CDB( (P_UC) , ( (P_UC)->acronimo )  , strlen( (P_UC)->acronimo)  , &cdb_make_add )
#define   Command2_insert_UniCurr_CDB_by_semestre(P_UC) 	Command2_insert_CDB( (P_UC) ,&( (P_UC)->semestre )  , sizeof( (P_UC)->semestre)  , &cdb_make_add )
#define       Command2_insert_UniCurr_CDB_by_tipo(P_UC) 	Command2_insert_CDB( (P_UC) ,&( (P_UC)->type )      , sizeof( (P_UC)->type)      , &cdb_make_add )
*/

#endif
