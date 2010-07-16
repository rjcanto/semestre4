#=======================================================================
# PSC   - Programação de Sistemas Computacionais
# Nome: 	Nuno Cancelo
# Numero:	31401
# Turma:	LI31N
# Semestre:	Verão 2009/2010
# Data:		Julho/2010
#-----------------------------------------------------------------------
# LEIC  - Licenciatura em Engenharia Informática e Computadores
# DEETC - Dep. de Eng. Electrónica e Telecomunicações e Computadores
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
#Geração de Todos os ficheiros
#=======================================================================
all: Command_Loader.o Command.o  ${BIBLIOTECAS}  ${CELL} Board.o   Minesweeper.o MineSweeper
#=======================================================================
#Geração de Command
#=======================================================================
Command.o: Command.c Command.h
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Command_Loader.o: Command_Loader.c Command_Loader.h Command.o
	${CC} ${WARINIGS}  ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
#=======================================================================
#Bibliotecas de Carregamento Dinâmico
#=======================================================================
%Cmd.so: %Cmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

%Cmd.o: %Cmd.c %Cmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 
#=======================================================================
#Geração de MineSweeper Board e Cell
#=======================================================================
Minesweeper.o: Minesweeper.c Minesweeper.h Command_Loader.o  Board.o
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Board.o: Board.c Board.h ${CELL}
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
%Cell.o: %Cell.c %Cell.h
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
#=======================================================================
#Geração do Executável
#=======================================================================
MineSweeper: Minesweeper.o Cell.o BombCell.o EmptyCell.o Board.o Command_Loader.o Command.o
	${CC} ${DINAMIC_LYBRARY} ${WARINIGS}  ${OUTPUT} $@ $^
	rm -f *.o 
#=======================================================================
#Clean
#=======================================================================
clean:
	rm -f *.o *.so MineSweeper.bin MineSweeper
	
