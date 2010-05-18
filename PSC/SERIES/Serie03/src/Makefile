GCC_OPTION=-g -Wall -pedantic

all:   xstrlen.o x1strcat.o x2strcat.o xstrcat.o  astrcat.o exercicio02.o Ex2 

xstrlen.o:	xstrlen.c
	gcc -c $(GCC_OPTION) -o $@ $^
	
x1strcat.o: x1strcat.c 
	gcc -c $(GCC_OPTION) -o $@ $^
	
x2strcat.o: x2strcat.c
	gcc -c $(GCC_OPTION) -o $@ $^
	
xstrcat.o:	xstrcat.c
	gcc -c $(GCC_OPTION) -o $@ $^
	
astrcat.o:	astrcat.s
	gcc -c $(GCC_OPTION) -o $@ $^
	

strcatlib.a: xstrlen.o x1strcat.o x2strcat.o xstrcat.o  astrcat.o  strcatlib.h
	ar rcs $@ $^

exercicio02.o: exercicio02.c  
	gcc -c  $(GCC_OPTION) -o $@ $^

Ex2: exercicio02.o strcatlib.h exercicio02.h strcatlib.a
	gcc -lrt $(GCC_OPTION) -o $@ $^


clean:  xstrlen.o x1strcat.o x2strcat.o xstrcat.o astrcat.o strcatlib.a exercicio02.o Ex2
	rm -rf  $^
