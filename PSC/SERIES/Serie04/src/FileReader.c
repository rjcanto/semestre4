#include "Common.h"
#include "Teacher.h"
#include "UniCurr.h"
#include "CDB_Builder.h"
#include "Command1.h"
#include <cdb.h>
#define BUFFER_SIZE 100

void fileparser(char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}

	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		/*Aloc de Unidade Curricular*/
		unicurr = UniCurr_new_fromString(buffer,delimiter);
		/*insert_UniCurr_by_acronimo_CDB(unicurr);*/
		/*Free de Unidade Curricular*/
		UniCurr_destroy(unicurr);
	}

	fclose(fp);

}



void dbReader(char* filename,char * key, void (*fx)(struct cdb* , char* , unsigned )){
	/*Start Database*/
	struct cdb cdb;
 	int fd;
	fd = open(filename, O_RDONLY);
	cdb_init(&cdb, fd);

	fx(&cdb, key, strlen(key));
	
	/*Close Database*/
	cdb_free(&cdb);
	close(fd);
}

void dblist(struct cdb* cdb, char* key, unsigned klen){
	char  *val;
	unsigned  vlen, vpos;	
	if (cdb_find(cdb, key, strlen(key)) > 0) {
		struct cdb_find cdbf; 
		cdb_findinit(&cdbf, cdb, key, strlen(key));
		while(cdb_findnext(&cdbf) > 0) {
		  vpos = cdb_datapos(cdb);
		  vlen = cdb_datalen(cdb);
		  val = malloc(vlen);
		  cdb_read(cdb, val, vlen, vpos);
		  /* handle the value */
		  CDB_UniCurr_parseLine(val);
		  free(val);
		}
	}
	else
	  printf("key=%s not found\n", key);	
}
void dblistAll(struct cdb* cdb, char* key, unsigned klen){
	unsigned cpos;
	int n;
	char *data;
	unsigned datalen;
	klen=0;datalen=0;n=0;
	cdb_seqinit( &cpos,cdb);
	while(cdb_seqnext(&cpos,cdb) > 0) {
		klen = cdb_keylen(cdb);
		key = malloc(klen + 1);
		cdb_read(cdb, key, klen, cdb_keypos(cdb));
		key[klen] = '\0';
		
		datalen = cdb_datalen(cdb);
		data = malloc(datalen + 1);
		cdb_read(cdb, data, datalen, cdb_datapos(cdb));
		data[datalen] = '\0';
		
		/* handle the value */
		printf("record %d: \n", ++n);
		CDB_UniCurr_parseLine(data);
		free(data); free(key);
	}
	printf("total records found: %d\n", n);
}




