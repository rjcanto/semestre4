CFLAGS = -Wall -pedantic -g
LDFLAGS = -ldl -rdynamic

%.class : %.java
	javac $<	

%.so : %.c
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $<

all: all_java all_c
all_java: Opers.class Sum.class Avg.class
all_c: Opers Sum.so Avg.so

Opers: Opers.o

clean :
	rm -f *~ *.o *.so *.class Opers *.gz

tar : clean
	tar -zcvf opers.tar.gz *.c *.h *.java makefile
