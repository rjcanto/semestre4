#include "Common.h"
#include "UniCurr.h"
#include "Teacher.h"
#include "CDB_Builder.h"
#include "FileReader.h"
#include <cdb.h>

int main(int argc,char** argv)
{
	char * filename = argv[argc-1];
	char * dsfilename="UC_DB.cdb";
	char * str="TAR";
	puts(filename);
	fileparser(filename);
	/*dbReaderAll(dsfilename);*/
	/*dbReadersingle(dsfilename,"TAR");*/
	/*dbReaderMultiple(dsfilename,"TAR");*/
	dbReader(dsfilename,str,dblist);
	getchar();
	dbReader(dsfilename,str,dblistAll);


return 0;	
}
