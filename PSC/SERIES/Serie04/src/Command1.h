#ifndef COMMAND1_H
#define COMMAND1_H
#include "Command.h"

void Command1_createDB();
void Command1_insert_CDB(void * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF *,void* ));
void Command1_destroyDB();
void Command1_getLine(CDBLF * result,void* t );
void Command1_queryCDB1(char* key);
void Command1_UniCurr_parseLine(char* line);

#define   Command1_insert_UniCurr_CDB_by_acronimo(P_UC) 	Command1_insert_CDB( (P_UC) , ( (P_UC)->acronimo )  , strlen( (P_UC)->acronimo)  , &cdb_make_add,Command1_getLine )
/*)#define Command1_insert_UniCurr_CDB_by_mec_number(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->mec_number ), sizeof( (P_UC)->mec_number), &cdb_make_add )
#define   Command1_insert_UniCurr_CDB_by_semestre(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->semestre )  , sizeof( (P_UC)->semestre)  , &cdb_make_add )
#define       Command1_insert_UniCurr_CDB_by_tipo(P_UC) 	Command1_insert_CDB( (P_UC) ,&( (P_UC)->type )      , sizeof( (P_UC)->type)      , &cdb_make_add )
*/
#endif
