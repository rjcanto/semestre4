CFLAGS = -Wall -pedantic -g

cmdDemo: cmdDemo.o command.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

readline.o: readline.s
	$(CC) -c -o $@ $^
cmdDemo.o command.o: command.h

command.o: readline.h

