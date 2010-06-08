
void dbReaderAll(char* filename){
	 struct cdb cdb;
     char *data;
     char *key;
	/* sequential database access */
	unsigned cpos;
	int n;     
	int fd;
	unsigned keylen, datalen;
	/* opening the database */
	fd = open(filename, O_RDONLY);
	cdb_init(&cdb, fd);
	/* initialize key and keylen here */
	keylen=0;datalen=0;
	
	cdb_seqinit( &cpos,&cdb);
	n = 0;
	
/*
puts("----------------------------------------------------------------------");
puts("Reading Database");
puts("----------------------------------------------------------------------");
*/
	
	while(cdb_seqnext(&cpos,&cdb) > 0) {
		keylen = cdb_keylen(&cdb);
		key = malloc(keylen + 1);
		cdb_read(&cdb, key, keylen, cdb_keypos(&cdb));
		key[keylen] = '\0';
		datalen = cdb_datalen(&cdb);
		data = malloc(datalen + 1);
		cdb_read(&cdb, data, datalen, cdb_datapos(&cdb));
		data[datalen] = '\0';
		++n;
		printf("record %d: \n", n);
		CDB_UniCurr_parseLine(data);
		free(data); free(key);
	}
	printf("total records found: %d\n", n);

	/* close the database */
	cdb_free(&cdb);
	close(fd);

}
void dbReaderMultiple(char* filename,char * key){
	 struct cdb cdb;
	int fd;
	char  *val;
	unsigned  vlen, vpos;

	fd = open(filename, O_RDONLY);
	cdb_init(&cdb, fd);
	
	if (cdb_find(&cdb, key, strlen(key)) > 0) {
		struct cdb_find cdbf; /* structure to hold current find position */
		cdb_findinit(&cdbf, &cdb, key, strlen(key)); /* initialize search of key */
		while(cdb_findnext(&cdbf) > 0) {
		  vpos = cdb_datapos(&cdb);
		  vlen = cdb_datalen(&cdb);
		  val = malloc(vlen);
		  cdb_read(&cdb, val, vlen, vpos);
		  /* handle the value */
		  CDB_UniCurr_parseLine(val);
		  free(val);
		}

	}
	else
	  printf("key=%s not found\n", key);
	
	cdb_free(&cdb);
	close(fd);
}
void fileparser(char* filename){
	FILE* fp= fopen(filename, "rb");
	UniCurr * unicurr;
	char buffer[BUFFER_SIZE];
	char delimiter ='|';
	char * dsfilename="UC_DB.cdb";
	
	int fd;
    struct cdb_make cdbm;


	if (fp == NULL){
			fprintf(stderr, "Unable to open the file. Check permition or disk space!\n");
			exit(2);
	}
	fd = open(dsfilename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if (cdb_make_start(&cdbm, fd) < 0) {
		puts("Aconteceu um erro na criação do ficheiro!");
		exit(-1);
	}
	
	puts("Processing the file!");
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
		unicurr = UniCurr_new_fromString(buffer,delimiter);
		/*UniCurr_toString(unicurr);*/
		CDB_insert_UniCurr_by_acronimo(unicurr, &cdbm);
		UniCurr_destroy(unicurr);
	}
    /* finalize and close the database */
    if (cdb_make_finish(&cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);
	fclose(fp);
	puts(dsfilename);
}
