#ifndef COMMAND1_H
#define COMMAND1_H
#include "Common.h"
#include "UniCurr.h"
#include <cdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "CDB_Builder.h"
void insert_Unicurr_CDB (UniCurr* this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int));


#define insert_UniCurr_CDB_by_mec_number(P_UC) 	insert_Unicurr_CDB( (P_UC) ,&( (P_UC)->mec_number ), sizeof( (P_UC)->mec_number), &cdb_make_add )
#define   insert_UniCurr_CDB_by_acronimo(P_UC) 	insert_Unicurr_CDB( (P_UC) , ( (P_UC)->acronimo )  , strlen( (P_UC)->acronimo)  , &cdb_make_add )
#define   insert_UniCurr_CDB_by_semestre(P_UC) 	insert_Unicurr_CDB( (P_UC) ,&( (P_UC)->semestre )  , sizeof( (P_UC)->semestre)  , &cdb_make_add )
#define       insert_UniCurr_CDB_by_tipo(P_UC) 	insert_Unicurr_CDB( (P_UC) ,&( (P_UC)->type )      , sizeof( (P_UC)->type)      , &cdb_make_add )


#endif
