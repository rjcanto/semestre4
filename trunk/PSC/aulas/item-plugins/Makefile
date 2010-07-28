
all: items Book.so CD.so

items: items.o
	gcc -o items items.o -ldl

items.o: items.c Item.h
	gcc -Wall -pedantic -c -o items.o items.c

Book.so: Book.o
	gcc -shared -o Book.so Book.o

Book.o: Book.c Item.h
	gcc -Wall -pedantic -fPIC -c -o Book.o Book.c

CD.so: CD.o
	gcc -shared -o CD.so CD.o

CD.o: CD.c Item.h
	gcc -Wall -pedantic -fPIC -c -o CD.o CD.c

clean:
	rm -f *.o *.so items
