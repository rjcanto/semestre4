#include "Common.h"
#include "FileReader.h"
#include "Command1.h"

/*#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "Command6.h"
#include "Command7.h"
#include "Command8.h"
*/ 
int main(int argc,char** argv)
{
	char * filename = argv[1];
	char * ofilename = argv[2];
	Command1* c1=Command1_ctor();
	puts(filename);
	
	fileparser(ofilename);
	fileparserUni(filename);
	 
	puts("Comando 1 (Pesquisa por Unidade Curricular)=> Press Enter:");getchar();
		c1->vptr->queryDB(c1,argv[3]);
	/*
	puts("Comando 3 (Pesquisa por Docente)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[4]);
		Command3_queryCDB1(argv[4]);
	puts("Comando 4 (Pesquisa por Dep Curriculares)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[3]);
		Command4_queryCDB1(argv[3]);
	puts("Comando 5 (Docente de uma Unidade Curricular)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[3]);		
		Command5_queryCDB1(argv[3]);
	puts("Comando 6 (Pesquisa por Docentes Responsaveis por Unidade Curricular)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[4]);	
		Command6_queryCDB1(argv[4]);
	puts("Comando 7 (Pesquisa por Tipo de Unidade Curricular)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[5]);	
		Command7_queryCDB1(argv[5]);
	puts("Comando 8 (Pesquisa por Semestre)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[6]);	
		Command8_queryCDB1(argv[6]);
	puts("Comando 2 (Lista Todos)=> Press Enter:");getchar();
	Command2_queryCDB1(NULL);
*/
	c1->vptr->dtor(c1);
return 0;	
}
