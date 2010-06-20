
public final class HelpCmd extends Command {
	public void exec(String line) {
		Command c;
		for(int i=0 ; i< cmds.length ; ++i) {
			c = cmds[i];
			System.out.println(c.prefix()+c.syntax()+" :");
			System.out.print("   - ");
			c.help();			
		}	
	}
	public void help() { System.out.println("Help for all commands."); }
	public char prefix() { return 'H'; }
}
