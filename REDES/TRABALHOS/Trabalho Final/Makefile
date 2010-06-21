CC 				= gcc
COMPILE_ONLY	= -c
OPTIONS			= -Wall -pedantic
OUTPUT_FILES	= -o

all: udpClient.o udpServer.o

udpClient.o: udpClient.c udpClient.h
	$(CC) $(OPTIONS) $(COMPILE_ONLY) $(OUTPUT_FILES) $@ $<
udpServer.o: udpServer.c udpServer.h
	$(CC) $(OPTIONS) $(COMPILE_ONLY)  $(OUTPUT_FILES) $@ $<
ServidorUDP: udpServer.o
	$(CC) $(OPTIONS) $(OUTPUT_FILES) $@ $<
ClienteUDP: udpClient.o
	$(CC) $(OPTIONS) $(OUTPUT_FILES) $@ $<
