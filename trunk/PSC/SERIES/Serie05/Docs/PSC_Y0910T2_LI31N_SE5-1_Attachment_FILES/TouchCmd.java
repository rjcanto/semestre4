
public class TouchCmd extends Command {
	public void exec(String txt) {
		int l = parseLine(txt);
		int c = parseCol(txt);
		Minesweeper.board.touch(l, c);
		if (Minesweeper.board.isSolved()) {
			System.out.println("You WIN.");
			Minesweeper.board.showAll();
		}
	}
	public void help() { System.out.println("Touch a cell. BUMMM on bomb."); }
	public char prefix() { return 'T'; }
	public String syntax() { return "<lin><col>"; }
}
