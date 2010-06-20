
public final class FlagCmd extends Command {
	public void exec(String txt) {
		int l = parseLine(txt);
		int c = parseCol(txt);
		Minesweeper.board.flag(l, c);
		if (Minesweeper.board.isSolved()) {
			System.out.println("You WIN.");
			Minesweeper.board.showAll();
		}
	}
	public void help() { System.out.println("Mark a cell with Bomb.");	}
	public char prefix() { return 'F'; }
	public String syntax() { return "<lin><col>"; }
}
