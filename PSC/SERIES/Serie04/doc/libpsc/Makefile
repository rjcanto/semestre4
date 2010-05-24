
xmtest: xmtest.o libpsc.a
	gcc -o xmtest xmtest.o libpsc.a

xmtest.o: xmtest.c xmalloc.h
	gcc -Wall -pedantic -c xmtest.c

xmalloc.o: xmalloc.c xmalloc.h ilist.h
	gcc -Wall -pedantic -c xmalloc.c

ilist.o: ilist.c ilist.h
	gcc -Wall -pedantic -c ilist.c

libpsc.a: ilist.o xmalloc.o
	ar rcs libpsc.a ilist.o xmalloc.o

clean:
	rm -f *.o *.a xmtest

