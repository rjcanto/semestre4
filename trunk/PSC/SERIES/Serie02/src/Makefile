GCC_OPTION= -Wall -pedantic
all:  exercicio1  exercicio2 exercicio3

exercicio1: exercicio1.c exercicio1.h astrcat.s
	gcc -g $(GCC_OPTION) -o $@ $^


exercicio2: mulff.c mulff.s
	gcc -g $(GCC_OPTION) -o $@ $^
	
exercicio3: exercicio3.c exercicio3.h ssearch.s
	gcc -g $(GCC_OPTION) -o $@ $^
