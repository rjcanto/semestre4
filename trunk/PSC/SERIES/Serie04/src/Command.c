#include "Command.h"
#define BUFFER_SIZE 100

unsigned short twoByte2UnsignedShort(char** twobyte){
	unsigned char a;
	unsigned char b;
	a=**twobyte++;
	b=**twobyte++;
	return(unsigned short)(a<<8)|b;
}

void unsignedShort2TwoBytes(char* dest, const unsigned short ush){
	unsigned char a,b;
	a= (ush>>8)&0x00FF;
	b= ( ush  )&0x00FF;
	*dest = a;
	*(dest+1)=b;
}

byte* CDB_field_equalize(char**  field, char * idx){
	if (*idx != 0){
		*field = strndup(idx+1,*idx);
		idx = idx + 1 + *idx;
	}else{
		*field=NULL;
		++idx;
	}
	return idx;
}

void Command_dbReader(char* filename,char * key, void (*fx)(struct cdb* , char* , unsigned, void (*parser)(char*) ), void (*parser)(char*) ){
	/*Start Database*/
	struct cdb cdb;
 	int fd;
	fd = open(filename, O_RDONLY);
	cdb_init(&cdb, fd);

		fx(&cdb, key, strlen(key),parser);
	
	/*Close Database*/
	cdb_free(&cdb);
	close(fd);
}
void Command_insert_CDB(void * this,struct cdb_make* cdbm,  void* key, unsigned int key_len, int (*fx)(struct cdb_make *, const void *,unsigned int,  const void *, unsigned int),void(*getline)(CDBLF *,void* )){
	CDBLF cdb_line;
	getline(&cdb_line,this);
	
		fx( cdbm, key, key_len, cdb_line.line, cdb_line.size);

	free(cdb_line.line);
	cdb_line.line=NULL;
}

void Command_dblist(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*)){
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
		  /*CDB_UniCurr_parseLine(val);*/
		  if (val != 0) parser(val);
		  free(val);
		}
		
	}
	else
	  printf("key=%s not found\n", key);
		
}
void Command_dblistAll(struct cdb* cdb, char* key, unsigned klen, void (*parser)(char*) ){
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
		++n;
		parser(data);
		free(data); free(key);
	}
	printf("total records found: %d\n", n);
}




