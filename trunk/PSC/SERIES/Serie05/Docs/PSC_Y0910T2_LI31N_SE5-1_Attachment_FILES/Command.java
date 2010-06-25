import java.io.*;

public abstract class Command {
	public abstract char prefix();
	public String syntax() { return "";}
	public abstract void exec(String line);
	public abstract void help();

	protected static Command cmds[];

	public static boolean load(String cfgFile) {
		int nLines;
		BufferedReader fin;
		try {
			fin = new BufferedReader( new FileReader(cfgFile) );
			fin.mark(1024);
			for (nLines=0 ; fin.readLine()!=null ; ++nLines) ;
			fin.reset();
			cmds = new Command[nLines];
			for(int i=0; i< nLines ; ++i)
				cmds[i] = (Command) Class.forName(fin.readLine()+"Cmd").newInstance();
			fin.close();
		} catch (Exception e) {
			System.err.println("Error reading file "+cfgFile+". "+e.getMessage()); return false;
		}
		return true;
	}
	
	public static void execute(String line) {
		if (line.length()==0) return;
		char prefix = Character.toUpperCase(line.charAt(0));
		for(int i=0 ; i< cmds.length ; ++i)
			if (cmds[i].prefix() == prefix) {
				cmds[i].exec(line.substring(1));
				return;
			}
		System.out.println("Invalid command "+prefix);
	}

	protected static int parseLine(String txt) {
		int val=0, i;
		char c;
		for (i=0 ; i<txt.length() && !Character.isDigit( txt.charAt(i) ) ; ++i) ;
		for ( ; i<txt.length() && Character.isDigit( c = txt.charAt(i) ) ; ++i) { val*=10; val+=c-'0'; }
		return val-1;
	}

	protected static int parseCol(String txt) {
		int val=0, i;
		char c;
		for (i=0 ; i<txt.length() && !Character.isLetter( txt.charAt(i) ) ; ++i) ;
		if (i<txt.length() && Character.isLetter( c = txt.charAt(i) ) ) { val+=Character.toUpperCase(c)-'A'; }
		return val;
	}
}
