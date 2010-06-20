
public final class ExitCmd extends Command {
	public void exec(String line) {
		System.out.println("Bye.");
		Minesweeper.exit=true;
	}
	public void help() { System.out.println("Terminate the game.");	}
	public char prefix() { return 'E'; }
}
