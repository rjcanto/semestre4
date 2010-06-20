%.class: %.java
	javac $<
	
all : Minesweeper.class Command.class Board.class commands

commands: TouchCmd.class NewCmd.class HelpCmd.class FlagCmd.class ExitCmd.class

clean:
	$(RM) *.class *.gz *~ 

tar: clean
	tar -cvzf se5.tar.gz *.java *.cfg makefile	
