#ifndef COMMAND_H
#define COMMAND_H
import java.io.*;

public abstract class Command {
	public abstract char prefix();
	public String syntax() { return ""; }
	public abstract void exec(String line);
	public abstract void help();

	protected static Command cmds[];

	public static boolean load(String cfgFile);
	
	public static void execute(String line);

	protected static int parseLine(String txt);

	protected static int parseCol(String txt) ;
}
#endif
