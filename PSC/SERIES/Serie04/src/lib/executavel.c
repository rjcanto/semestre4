#include "Common.h"
#include "UniCurr.h"
#include "Teacher.h"
#include "CDB_Builder.h"
#include <cdb.h>

int main(int argc,char** argv)
{
	 UniCurr * t1 = t1;
	 UniCurr * t2 = t2;
	 UniCurr * t3 = t3;
	 UniCurr * t4 = t4;
	 UniCurr * t5 = t5;
	 Teacher * tt1 = 0;
	 Teacher * tt2 = 0;

	 char string1[]="PDSI|P|32|Com||Processamento Digital de Sinal e Imagem|690";
	 char string2[]="MPD|P|40|POO||Modelação e Padrões de Desenho|1619";
	 char string3[]="AVE|B|8||PSC;AED|Ambientes Virtuais de Execução|697";
	 char string4[]="LS|B|8|POO;SI1|PSC;AED|Laboratório de Software|889";
	 char string5[]="819|Acilina Nascimento Caneco|d819@deetc.isel.pt";
	 char* search;
	 char filename[]="CDB_TESTE_UC";
     int fd;
     struct cdb_make cdbm;
     struct cdb cdb;
     char *data;
     unsigned datalen;

	 search = argv[argc-1];
	 
	t1 = UniCurr_new("EICARAMBA","EIC","XPTO;ABRA",NULL,123,'B',1);
	t2 = UniCurr_new_fromString(string1,'|');
	t3 = UniCurr_new_fromString(string2,'|');
	t4 = UniCurr_new_fromString(string3,'|');
	t5 = UniCurr_new_fromString(string4,'|');
	tt1 = Teacher_new("Adolfo","Dias",123);
	tt2 = Teacher_new_FromString(string5,'|');
/*
puts("----------------------------------------------------------------------");
puts("Building Database");
puts("----------------------------------------------------------------------");
*/

        fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
        if (cdb_make_start(&cdbm, fd) < 0) {
			puts("Aconteceu um erro na criação do ficheiro!");
			exit(-1);
		}
		
		CDB_insert_Teacher_by_mec_Number(tt1, &cdbm);
		CDB_insert_Teacher_by_mec_Number(tt2, &cdbm);
		/*UniCurr_toString(t1);*/
		/*CDB_insert_UniCurr_by_acronimo(t1, &cdbm);*/
		/*UniCurr_toString(t2);*/
		/*CDB_insert_UniCurr_by_acronimo(t2, &cdbm);*/
		/*UniCurr_toString(t3);*/
		/*CDB_insert_UniCurr_by_acronimo(t3, &cdbm);*/
		/*UniCurr_toString(t4);*/
		/*CDB_insert_UniCurr_by_acronimo(t4, &cdbm);*/
		/*UniCurr_toString(t4);*/
		/*CDB_insert_UniCurr_by_acronimo(t5, &cdbm);*/
		
        

        /* finalize and close the database */
    if (cdb_make_finish(&cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);

/*
puts("----------------------------------------------------------------------");
puts("Reading Database");
puts("----------------------------------------------------------------------");
*/

        fd = open(filename, O_RDONLY);
        cdb_init(&cdb, fd);
        /* initialize key and keylen here */

        /* single-record search.*/
        
        if (cdb_find(&cdb, search, strlen(search)) > 0) {
         
          datalen = cdb_datalen(&cdb);
          data = malloc(datalen + 1);
			cdb_read(&cdb, data, datalen, cdb_datapos(&cdb));
			
			data[datalen] = '\0';

			
			CDB_UniCurr_parseLine(data);
			
          free(data);
        }
        else
          printf("key=%s not found\n", search);
		
        cdb_free(&cdb);
        close(fd);

/*
puts("----------------------------------------------------------------------");
puts("Kill Instances");
puts("----------------------------------------------------------------------");
*/
	UniCurr_destroy(t1);
	UniCurr_destroy(t2);
	UniCurr_destroy(t3);
	UniCurr_destroy(t4);
	UniCurr_destroy(t5);
	Teacher_destroy(tt2);
	Teacher_destroy(tt1);

return 0;	
}
