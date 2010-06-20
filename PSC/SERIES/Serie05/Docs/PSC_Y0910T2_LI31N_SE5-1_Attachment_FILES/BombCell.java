
public final class BombCell extends Cell {
	boolean exploded = false;
    protected char getView() { return exploded ? '@' : '+'; }
    public void touch() {
    	show();
    	exploded = true;
    	System.out.println("BUMMMM.");
    	Minesweeper.board.showAll();
    }
    public boolean isBomb() { return true; }
}
