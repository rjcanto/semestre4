CC = gcc
OPTIONS = -Wall -pedantic -o
COMPILE_ONLY = -c 
	
all: Test UniCurr.c UniCurr.h LinkedList.c LinkedList.h DepList.c DepList.h

UniCurr.o: UniCurr.c UniCurr.h 
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<

LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(COMPILE_ONLY) $(OPTIONS) $@ $<

Test: UniCurr.c LinkedList.c DepList.c
	$(CC) $(OPTIONS) $@ $^

clean:
	rm -rf *.o Test
