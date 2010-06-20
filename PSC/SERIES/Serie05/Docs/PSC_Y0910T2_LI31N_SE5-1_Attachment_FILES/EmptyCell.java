
public final class EmptyCell extends Cell {
  private final static int[] difLin = {-1,-1,-1, 0, 0, 1, 1, 1 },
                             difCol = {-1, 0, 1,-1, 1,-1, 0, 1 }; 
  private final int lin, col;
  private int number;
  
  public EmptyCell(int l, int c) {
	lin=l; col=c; 
  }
  
  protected char getView() { return number==0 ? ' ' : (char)('0'+number); }

  public void touch() {
	if (isShown()) return;
	show();
	Board b = Minesweeper.board;
	for(int i=0; i<difLin.length ; ++i)
	  if (b.isBomb(lin + difLin[i], col + difCol[i]))
		 ++number;
	if (number==0)
	  for(int i=0; i<difLin.length ; ++i)
		b.touch(lin + difLin[i], col + difCol[i]);
  }
}
