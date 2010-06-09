CC = gcc
OPTIONS = -Wall -pedantic -o
COMPILE_ONLY = -c 
CDB_LIBRARY = -lcdb

#all: Command.o DepList.o LinkedList.o Common.o Teacher.o UniCurr.o Command1.o CDB_Builder.o Executavel.o Serie04
all: Command.o Common.o Teacher.o UniCurr.o Command1.o Command2.o Command3.o FileReader.o CDB_Builder.o Executavel.o Serie04

Command.o: Command.c Command.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<

#DepList.o: DepList.c DepList.h
#	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command1.o: Command1.c Command1.h Command.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
	
Command2.o: Command2.c Command2.h Command.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<

Command3.o: Command3.c Command3.h Command.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<

FileReader.o: FileReader.c FileReader.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
	
#LinkedList.o: LinkedList.c LinkedList.h
#	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
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
#Serie04: Executavel.o Command.o DepList.o LinkedList.o Teacher.o UniCurr.o Command1.o CDB_Builder.o Common.o
Serie04: Executavel.o Command.o Teacher.o UniCurr.o Command1.o Command2.o Command3.o  FileReader.o CDB_Builder.o Common.o
	$(CC) $(CDB_LIBRARY) $(OPTIONS)  $@ $^

clean:
	rm -rf *.o Test Serie04
