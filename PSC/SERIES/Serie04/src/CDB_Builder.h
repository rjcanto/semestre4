#ifndef CDB_BUILDER_H
#define CDB_BUILDER_H

#include <cdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"


/*
void CDB_Teacher_getLine(CDBLF * result, Teacher* this);
void CDB_insert_Teacher (Teacher* this, struct cdb_make* cdbm, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int));
#define CDB_insert_Teacher_by_mec_Number(T,C) CDB_insert_Teacher((T),C,&((T)->mec_number), sizeof((T)->mec_number),&cdb_make_add);
*/
/*void CDB_insert_Teacher_by_mec_Number(Teacher * this,struct cdb_make* cdbm);*/

/*
void CDB_UniCurr_getLine(CDBLF * result,UniCurr* this );
void CDB_UniCurr_parseLine(char* line);

void CDB_insert_Unicurr (UniCurr * this, struct cdb_make* cdbm, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int));
#define CDB_insert_UniCurr_by_mec_number(P_UC, P_CDB) CDB_insert_Unicurr((P_UC),(P_CDB),&((P_UC)->mec_number), sizeof((P_UC)->mec_number),&cdb_make_add);
#define CDB_insert_UniCurr_by_acronimo(P_UC, P_CDB) CDB_insert_Unicurr((P_UC),(P_CDB),( (P_UC)->acronimo), strlen((P_UC)->acronimo),&cdb_make_add);
#define CDB_insert_UniCurr_by_semestre(P_UC, P_CDB) CDB_insert_Unicurr((P_UC),(P_CDB),&((P_UC)->semestre), sizeof((P_UC)->semestre),&cdb_make_add);
#define CDB_insert_UniCurr_by_tipo(P_UC, P_CDB) CDB_insert_Unicurr((P_UC),(P_CDB),&((P_UC)->type), sizeof((P_UC)->type),&cdb_make_add);
*/
#endif

