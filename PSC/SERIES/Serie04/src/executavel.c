#include "Common.h"
/*#include "UniCurr.h"*/
/*#include "Teacher.h"*/
/*#include "CDB_Builder.h"*/
#include "FileReader.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
int main(int argc,char** argv)
{
	char * filename = argv[1];
	char * ofilename = argv[2];
	
	puts(filename);
	
	fileparser(ofilename);
	fileparserUni(filename);
	 
	/*dbReaderAll(dsfilename);*/
	/*dbReadersingle(dsfilename,"TAR");*/
	/*dbReaderMultiple(dsfilename,"TAR");*/

	/*Command1_queryCDB1(str);*/
	/*puts("Press Enter:");getchar();
	Command2_queryCDB1();
	puts("Press Enter:");getchar();
	Command3_queryCDB1(argv[3]);*/
	
	puts("Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[3]);
	/*Command3_queryCDB1(argv[3]);*/
	Command4_queryCDB1(argv[3]);

	/*dbReader(dsfilename,str,dblistAll);*/


return 0;	
}
