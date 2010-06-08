#include "Common.h"
#include "UniCurr.h"
#include "Teacher.h"
#include "CDB_Builder.h"
#include "FileReader.h"
#include <cdb.h>

int main(int argc,char** argv)
{
	char * filename = argv[argc-1];
	puts(filename);
	fileparser(filename);


return 0;	
}
