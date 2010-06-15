#include "Command2.h"
/**
 * - Criação de Base de Dados com a Informação das Unidade Curriculares
 * - Lista Todos as entradas da Base de dados
 * 
 * */

void Command1_parseLine(char* line);
void Command3_parseLine(char* line);


char* Command2_filename="UCbyAcronimo.cdb";
struct cdb_make Command2_cdbm;
int fd;

void Command2_createDB(){
	puts("Method Not Implemented. This only a 'list all' command.");
}

void Command2_insert_CDB(void * this){
	puts("Method Not Implemented. This only a 'list all' command.");
}


void Command2_queryCDB1(char * str){
	
	Command_dbReader("UCbyAcronimo.cdb","",Command_dblistAll,Command1_parseLine);
	Command_dbReader("TeacherbyMecNbr.cdb","",Command_dblistAll,Command3_parseLine);
}

void Command2_destroyDB(){
	puts("Method Not Implemented. This only a 'list all' command.");
}
