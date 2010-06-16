#include "Common.h"
#include "FileReader.h"
#include "Command1.h"

#include "Command2.h"
#include "Command3.h"
/*#include "Command4.h"
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
	Command2* c2=Command2_ctor();
	Command3* c3=Command3_ctor();
	Command4* c4=Command4_ctor();
	Command5* c5=Command5_ctor();
	Command6* c6=Command6_ctor();
	Command7* c7=Command7_ctor();
	puts(filename);
	
	fileparser(ofilename);
	fileparserUni(filename);
	printf("Pesquisando %s:\n",argv[3]);
	puts("Comando 1 (Pesquisa por Unidade Curricular)=> Press Enter:");getchar();
	c1->super.vptr->queryDB(c1,argv[3]);
	/*
	
	
	*/ 
	printf("Pesquisando %s:\n",argv[4]);
	puts("Comando 3 (Pesquisa por Docente)=> Press Enter:");getchar();
	c3->super.vptr->queryDB(c3,argv[4]);

	printf("Pesquisando %s:\n",argv[3]);
	puts("Comando 4 (Pesquisa por Dep Curriculares)=> Press Enter:");getchar();
	c4->super.vptr->queryDB(c4,argv[3]);

	printf("Pesquisando %s:\n",argv[3]);
	puts("Comando 5 (Docente de uma Unidade Curricular)=> Press Enter:");getchar();
	c5->super.vptr->queryDB(c5,argv[3]);

	puts("Comando 6 (Pesquisa por Docentes Responsaveis por Unidade Curricular)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[4]);	
	c6->super.vptr->queryDB(c6,argv[4]);
	
	puts("Comando 7 (Pesquisa por Tipo de Unidade Curricular)=> Press Enter:");getchar();
	printf("Pesquisando %s:\n",argv[5]);	
	c7->super.vptr->queryDB(c7,argv[5]);
	/*
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
	*/
	puts("Comando 2 (Lista Todos)=> Press Enter:");getchar();
	c2->super.vptr->queryDB(c2,"");


	c1->super.vptr->dtor(c1);
	c2->super.vptr->dtor(c2);
	c3->super.vptr->dtor(c3);
	c4->super.vptr->dtor(c4);
	c5->super.vptr->dtor(c5);
	c6->super.vptr->dtor(c6);
	c7->super.vptr->dtor(c7);
return 0;	
}
