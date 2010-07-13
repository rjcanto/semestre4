#=======================================================================
# PSC   - Programação de Sistemas Computacionais
# Nome: 	Nuno Cancelo
# Numero:	31401
# Turma:	LI31N
# Semestre:	Verão 2009/2010
# Data:		Junho/2010
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
BIBLIOTECAS		= HelpCmd.so TouchCmd.so NewCmd.so FlagCmd.so ExitCmd.so
CELL			= EmptyCell.o Cell.o BombCell.o
#=======================================================================
#Geração de Todos os ficheiros
#=======================================================================
all: Command_Loader.o Command.o  ${BIBLIOTECAS}  ${CELL} Board.o   Minesweeper.o MineSweeper
#CommandTest
#=======================================================================
#
#=======================================================================
Command.o: Command.c Command.h
	${CC} ${WARINIGS} ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Command_Loader.o: Command_Loader.c Command_Loader.h Command.o
	${CC} ${WARINIGS}  ${POS_INDEPENDENT} ${COMPILE_ONLY} ${OUTPUT} $@ $<
#=======================================================================
#Bibliotecas de Carregamento Dinâmico
#=======================================================================
HelpCmd.so: HelpCmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

HelpCmd.o: HelpCmd.c HelpCmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 

TouchCmd.so: TouchCmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

TouchCmd.o: TouchCmd.c TouchCmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 

NewCmd.so: NewCmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

NewCmd.o: NewCmd.c NewCmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 

FlagCmd.so: FlagCmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

FlagCmd.o: FlagCmd.c FlagCmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 

ExitCmd.so: ExitCmd.o Command.o
	${CC} ${SHARED_LYBRARY} ${WARINIGS} ${OUTPUT}  $@ $^

ExitCmd.o: ExitCmd.c ExitCmd.h Command.h
	${CC} ${POS_INDEPENDENT} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $< 
#=======================================================================
#
#=======================================================================
Minesweeper.o: Minesweeper.c Minesweeper.h Command_Loader.o  Board.o
	${CC} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Board.o: Board.c Board.h ${CELL}
	${CC} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $<
Cell.o: Cell.c Cell.h
	${CC} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $<
BombCell.o: BombCell.c BombCell.h Cell.o
	${CC} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $<
EmptyCell.o: EmptyCell.c EmptyCell.h Cell.o
	${CC} ${WARINIGS} ${COMPILE_ONLY} ${OUTPUT} $@ $<
#=======================================================================
#DEBUG
#=======================================================================
#CommandTest.o: CommandTest.c CommandTest.h
#	${CC} ${WARINIGS}  ${COMPILE_ONLY} ${OUTPUT} $@ $<
#CommandTest: CommandTest.o Command.o
#	${CC} -ldl ${WARINIGS}  ${OUTPUT} $@ $^
#=======================================================================
#Geração do Executável
#=======================================================================
MineSweeper: Minesweeper.o Cell.o BombCell.o EmptyCell.o Board.o Command_Loader.o Command.o
#MineSweeper: Minesweeper.o Board.o ${CELL}
	${CC} ${DINAMIC_LYBRARY} ${WARINIGS}  ${OUTPUT} $@ $^
#=======================================================================
#Clean
#=======================================================================
clean:
	rm -f *.o *.so
