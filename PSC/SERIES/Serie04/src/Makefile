CC 				= gcc
OPTIONS 		= -Wall -pedantic -o
COMPILE_ONLY 	= -c 
CDB_LIBRARY 	= -lcdb
COMMAND_FILES 	=  Command0.o  Command1.o Command2.o Command3.o Command4.o Command5.o Command6.o Command7.o Command8.o Command9.o Command10.o

all: Common.o Teacher.o UniCurr.o $(COMMAND_FILES) CommandLib.a  Executavel.o Serie04 
#---------
#Comandos
#---------
Command0.o: Command.c Command.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command1.o: Command1.c Command1.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command2.o: Command2.c Command2.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command3.o: Command3.c Command3.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command4.o: Command4.c Command4.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command5.o: Command5.c Command5.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command6.o: Command6.c Command6.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command7.o: Command7.c Command7.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command8.o: Command8.c Command8.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command9.o: Command9.c Command9.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
Command10.o: Command10.c Command10.h Command0.o
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
CommandLib.a: $(COMMAND_FILES)
	ar rcs $@ $^
	rm -rf Command[0-9]*.o

Common.o: Common.c Common.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
#-----------------------
#U. Curricular e Docente
#------------------------
Teacher.o: Teacher.c Teacher.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<
UniCurr.o: UniCurr.c UniCurr.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<



Executavel.o: executavel.c
	$(CC) $(COMPILE_ONLY) $(CDB_LIBRARY) $(OPTIONS) $@ $<
Serie04: Executavel.o Teacher.o UniCurr.o CommandLib.a  Common.o
	$(CC) $(CDB_LIBRARY) $(OPTIONS)  $@ $^

clean:
	rm -rf *.o Test Serie04 *.cdb
