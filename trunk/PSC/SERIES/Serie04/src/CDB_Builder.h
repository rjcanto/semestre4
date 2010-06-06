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

typedef struct cdb_line_fields{
	unsigned short int size;
	char * line;
}CDBLF;

void CDB_Teacher_getLine(CDBLF * result, Teacher* this);
void CDB_insert_Teacher (Teacher* this, struct cdb_make* cdbm, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int));
void CDB_insert_Teacher_by_mec_Number(Teacher * this,struct cdb_make* cdbm);
void CDB_UniCurr_getLine(CDBLF * result,UniCurr* this );
void CDB_insert_Unicurr ( UniCurr * this, struct cdb_make* cdbm, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int));
void CDB_insert_UniCurr_by_mec_number(UniCurr * this,struct cdb_make *cdbm);
void CDB_insert_UniCurr_by_acronimo(UniCurr * this,struct cdb_make *cdbm);
void CDB_insert_UniCurr_by_semestre(UniCurr * this,struct cdb_make *cdbm);
#endif

