#ifndef EMPTYCELL_H
#define EMPTYCELL_H
  private final static int[] difLin = {-1,-1,-1, 0, 0, 1, 1, 1 },
                             difCol = {-1, 0, 1,-1, 1,-1, 0, 1 }; 
  private final int lin, col;
  private int number;
  
  public EmptyCell(int l, int c);
  
  protected char EmptyCell_getView();

  public void EmptyCell_touch();
}
#endif
