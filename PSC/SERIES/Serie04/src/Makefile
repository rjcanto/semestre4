CC = gcc
OPTIONS = -Wall -pedantic -o
COMPILE_ONLY = -c 
CDB_LIBRARY = -lcdb

all: FileReader.o DepList.o LinkedList.o Common.o Teacher.o UniCurr.o CDB_Builder.o Executavel.o Serie04

FileReader.o: FileReader.c FileReader.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<


DepList.o: DepList.c DepList.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
	
LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Common.o: Common.c Common.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Teacher.o: Teacher.c Teacher.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
UniCurr.o: UniCurr.c UniCurr.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
CDB_Builder.o: CDB_Builder.c CDB_Builder.h
	$(CC) $(COMPILE_ONLY) $(CDB_LIBRARY) $(OPTIONS) $@ $<
Executavel.o: executavel.c
	$(CC) $(COMPILE_ONLY) $(CDB_LIBRARY) $(OPTIONS) $@ $<
Serie04: Executavel.o FileReader.o DepList.o LinkedList.o Teacher.o UniCurr.o  CDB_Builder.o Common.o
	$(CC) $(CDB_LIBRARY) $(OPTIONS)  $@ $^

clean:
	rm -rf *.o Test
