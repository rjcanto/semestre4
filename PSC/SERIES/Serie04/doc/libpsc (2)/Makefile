
# Activar uma das duas linhas seguintes:
#OPTMALLOC=-DSTDMALLOC
OPTMALLOC=

all: finder xmtest

finder: finder.o libpsc.a
	gcc -o finder finder.o libpsc.a

xmtest: xmtest.o libpsc.a
	gcc -o xmtest xmtest.o libpsc.a

finder.o: finder.c xmalloc.h dlist.h
	gcc -Wall -pedantic $(OPTMALLOC) -c finder.c

xmtest.o: xmtest.c xmalloc.h
	gcc -Wall -pedantic $(OPTMALLOC) -c xmtest.c

libpsc.a: dlist.o xmalloc.o
	ar rcs libpsc.a dlist.o xmalloc.o

xmalloc.o: xmalloc.c xmalloc.h dlist.h
	gcc -Wall -pedantic -c xmalloc.c

dlist.o: dlist.c dlist.h
	gcc -Wall -pedantic -c dlist.c

clean:
	rm -f *.o *.a xmtest finder

