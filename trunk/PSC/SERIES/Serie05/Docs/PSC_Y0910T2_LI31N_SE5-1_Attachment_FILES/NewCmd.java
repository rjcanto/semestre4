
public class NewCmd extends Command {
	public void exec(String txt) {
		Minesweeper.board=new Board();
	}
	public void help() { System.out.println("Create a new board.");	}
	public char prefix() { return 'N'; }
}
