



struct{
	char* db_filename;
	char option;
	void Command4_createDB();
	void Command4_getLine(CDBLF * result,void* t );
	void Command4_parseLine(char* line);
	void Command4_insert_CDB_by_Dependencias(void * this);
	void Command4_queryCDB1(char* key);
	void Command4_destroyDB();
	
	void syntax();	
}
