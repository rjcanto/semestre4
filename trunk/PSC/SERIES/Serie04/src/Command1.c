#include "Command1.h"

static char* filename="UCbyAcronimo.cdb";
static struct cdb_make cdbm;
static int fd;
void Command1_createDB(){
	fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&cdbm, fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}	
}
void Command1_insert_Unicurr_CDB(UniCurr * this, void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int)){
	CDBLF cdb_line;
	CDB_UniCurr_getLine(&cdb_line,this);

		fx( &cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}
void Command1_queryCDB1(char* key){
	dbReader(filename,key,dblist);	
}

void Command1_queryCDB2(){
	dbReader(filename,"",dblistAll);	
}
void Command1_destroyDB(){
    if (cdb_make_finish(&cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);
	
}
