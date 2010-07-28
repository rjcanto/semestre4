CC=gcc
CFLAGS=-c -g -Wall -pedantic
LDFLAGS=
LIBS=-lm
EXENAME=-o $@
OBJNAME=-o $@

DEL=rm

all: testp jtestp.class

testp: testp.o Point.o Point3D.o ColoredPoint.o
	$(CC) $(LDFLAGS) $(EXENAME) testp.o Point.o Point3D.o ColoredPoint.o $(LIBS)

testp.o: testp.c Point3D.h Point.h
	$(CC) $(CFLAGS) $(OBJNAME) testp.c

Point.o: Point.c Point.h
	$(CC) $(CFLAGS) $(OBJNAME) Point.c

Point3D.o: Point3D.c Point3D.h Point.h
	$(CC) $(CFLAGS) $(OBJNAME) Point3D.c

ColoredPoint.o: ColoredPoint.c ColoredPoint.h Point.h
	$(CC) $(CFLAGS) $(OBJNAME) ColoredPoint.c

jtestp.class: jtestp.java
	javac jtestp.java

clean:
	$(DEL) *.o testp *.class
