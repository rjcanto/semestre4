#=======================================================================
# PSC   - Programa��o de Sistemas Computacionais
# Nome: 	Nuno Cancelo
# Numero:	31401
# Turma:	LI31N
# Semestre:	Ver�o 2009/2010
# Data:		Julho/2010
#-----------------------------------------------------------------------
# LEIC  - Licenciatura em Engenharia Inform�tica e Computadores
# DEETC - Dep. de Eng. Electr�nica e Telecomunica��es e Computadores
# ISEL  - Instituto Superior de Engenharia de Lisboa
#=======================================================================
CC 				= gcc
WARINIGS		= -g -Wall -pedantic
OUTPUT 			= -o
COMPILE_ONLY 	= -c 
DINAMIC_LYBRARY = -ldl 
POS_INDEPENDENT = -fPIC
SHARED_LYBRARY  = -shared -lm
BIBLIOTECAS		= HelpCmd.so TouchCmd.so NewCmd.so FlagCmd.so ExitCmd.so LoadCmd.so SaveCmd.so 
CELL			= EmptyCell.o Cell.o BombCell.o
#=======================================================================
#Gera��o de Todos os ficheiros
#=======================================================================
all: Command_Loader.o Command.o  ${BIBLIOTECAS}  ${CELL} Board.o   Minesweeper.o MineSweeper
#=======================================================================
#Gera��o de Command
#=======================================================================
Command.o: Command.c Command.h
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Command_Loader.o: Command_Loader.c Command_Loader.h Command.o
	${CC} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $<
#=======================================================================
#Bibliotecas de Carregamento Din�mico
#=======================================================================
%Cmd.so: %Cmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

%Cmd.o: %Cmd.c %Cmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 
#=======================================================================
#Gera��o de MineSweeper Board e Cell
#=======================================================================
Minesweeper.o: Minesweeper.c Minesweeper.h Command_Loader.o  Board.o
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Board.o: Board.c Board.h ${CELL}
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
%Cell.o: %Cell.c %Cell.h
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
#=======================================================================
#Gera��o do Execut�vel
#=======================================================================
MineSweeper: Minesweeper.o Cell.o BombCell.o EmptyCell.o Board.o Command_Loader.o Command.o
	${CC} -rdynamic ${DINAMIC_LYBRARY} ${WARINIGS}  ${OUTPUT} $@ $^
	rm -f *.o 
#=======================================================================
#Clean
#=======================================================================
clean:
	rm -f *.o *.so  MineSweeper
#MineSweeper.bin
	
