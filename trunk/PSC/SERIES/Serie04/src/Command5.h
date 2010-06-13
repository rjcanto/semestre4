#ifndef COMMAND5_H
#define COMMAND5_H
#include "Command.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "UniCurr.h"
#include "Teacher.h"
void Command5_createDB();
void Command5_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF *,void* ));
void Command5_destroyDB();

void Command5_insert_CDB_by_MecNbr(void * this);
void Command5_queryCDB1(char* key);
void Command5_parseLine(char* line);
void Command5_getLine(CDBLF * result,void* this );

/*define   Command3_insert_CDB_by_mec_number(P_UC) 	Command3_insert_CDB( (P_UC) , ( (P_UC)->mec_number )  , sizeof( (P_UC)->mec_number)  , &cdb_make_add )*/
/*
#define Command1_insert_UniCurr_CDB_by_mec_number(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->mec_number ), sizeof( (P_UC)->mec_number), &cdb_make_add )
#define   Command1_insert_UniCurr_CDB_by_acronimo(P_UC) 	Command1_insert_CDB( (P_UC) , ( (P_UC)->acronimo )  , strlen( (P_UC)->acronimo)  , &cdb_make_add )
#define   Command1_insert_UniCurr_CDB_by_semestre(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->semestre )  , sizeof( (P_UC)->semestre)  , &cdb_make_add )
#define       Command1_insert_UniCurr_CDB_by_tipo(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->type )      , sizeof( (P_UC)->type)      , &cdb_make_add )
*/

#endif
