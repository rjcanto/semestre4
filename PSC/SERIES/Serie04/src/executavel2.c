#include "Common.h"
#include "UniCurr.h"
#include "Teacher.h"
#include "CDB_Builder.h"
#include "FileReader.h"
#include "Command2.h"
#include <cdb.h>

int main(int argc,char** argv)
{
	char * filename = argv[argc-1];
	
	char * str="TAR";
	puts(filename);
	Command2 c2=Command2_new();
	
	Command2_queryDB(str);
	/*fileparser(filename);*/
	/*dbReaderAll(dsfilename);*/
	/*dbReadersingle(dsfilename,"TAR");*/
	/*dbReaderMultiple(dsfilename,"TAR");*/
	/*Command1_queryCDB1(str);*/
	/*getchar();*/
	/*Command1_queryCDB2();*/
	/*dbReader(dsfilename,str,dblistAll);*/

	c2.vptr->destroyDB;
	
return 0;	
}
