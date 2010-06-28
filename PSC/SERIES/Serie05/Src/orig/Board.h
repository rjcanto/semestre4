#ifndef BOARD_H
#define BOARD_H
	public static final int LINES=6, COLS=6, BOMBS=5;

	private final Cell[][] cells = new Cell[LINES][COLS];
	
	private int bombs; // number of bombs not flagged. 
	private int hides; // number of cells not touched.

	public boolean isSolved();

	public Board();
	
	private void putBomb(int n);
	
	private static void printLine();

	public void print() ;
	
	public static boolean isValid(int l, int c);
	public boolean isBomb(int l, int c);

	public void touch(int l, int c);

	public void showAll();

	public void flag(int l, int c);

#endif
