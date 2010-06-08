#include "Command1.h"

static char* filename="";
static struct cdb_make cdbm;
static int fd;
static void createDB(){
	fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&cdbm, fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}
void insert_Unicurr_CDB(UniCurr * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int)){
	CDBLF cdb_line;
	CDB_UniCurr_getLine(&cdb_line,this);

		fx( &cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}

static void destroyDB(){
    if (cdb_make_finish(&cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);
	
}
