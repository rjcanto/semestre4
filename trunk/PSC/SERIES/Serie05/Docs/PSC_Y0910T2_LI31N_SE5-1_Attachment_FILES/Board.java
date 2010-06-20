
public final class Board {
	public static final int LINES=6, COLS=6, BOMBS=5;

	private final Cell[][] cells = new Cell[LINES][COLS];
	
	private int bombs; // number of bombs not flagged. 
	private int hides; // number of cells not touched.

	public boolean isSolved() { return hides==bombs; }

	public Board() {
	  hides = LINES*COLS;
	  for( ; bombs < BOMBS ; ++bombs)
		putBomb((int)(Math.random()*(hides-bombs)));
	  for(int l=0 ; l<LINES ; ++l)
	    for(int c=0; c<COLS ; ++c)
	   	  if (cells[l][c]==null)
	   		cells[l][c]=new EmptyCell(l,c);
	}
	
	private void putBomb(int n) {
	  assert n>=0 : n;
	  for(int l=0 ; l<LINES ; ++l)
		for(int c=0; c<COLS ; ++c)
		  if (cells[l][c]==null) {
			  if (n==0) { cells[l][c]=new BombCell(); return; }
	          --n;
		  }
	  assert false : n;
	}
	
	private static void printLine() {
		  System.out.print("   +");
		  for(int c=0; c<COLS ; ++c) System.out.print("--");
		  System.out.println("-+");
	}

	public void print() {
	  System.out.printf("%02d  ",bombs);
	  for(int c=0; c<COLS ; ++c) System.out.printf(" %c", 'A'+c);
	  System.out.printf("   %02d", hides);
	  System.out.println();
	  printLine();
	  for(int l=0 ; l<LINES ; ++l) {
		System.out.printf("%2d |",l+1);
		for(int c=0; c<COLS ; ++c) {
			System.out.print(' ');
			cells[l][c].print();
		}
		System.out.println(" |");
	  }
	  printLine();
	}
	
	public static boolean isValid(int l, int c) {
      return l >= 0 && l < Board.LINES && c >= 0 && c < Board.COLS;	
	}

	public boolean isBomb(int l, int c) {
	  return isValid(l,c) && cells[l][c].isBomb();
    }

	public void touch(int l, int c) {
	  if (isValid(l, c)) {
		  Cell cell = cells[l][c];
		  if (cell.isShown() || cell.isFlagged()) return;
		  cell.touch();
		  hides--;
	  }
	}

	public void showAll() {
	  for(int l=0 ; l<LINES ; ++l)
		for(int c=0; c<COLS ; ++c) cells[l][c].show();
	  hides = 0;
	}

	public void flag(int l, int c) {
		if (isValid(l,c)) {
			  Cell cell = cells[l][c];
			  if (cell.isShown()) return;
			  cell.toggleFlag();
			  if (cell.isFlagged()) { bombs--; hides--; }
			  else { bombs++; hides++; }
		}
	}
}
