#ifndef CELL_H
#define CELL_H
  protected abstract char getView();
  public abstract void touch();
  public boolean isBomb();

  private enum Stat;
  
  Stat stat=Stat.NONE;

  public final void print();
  public final boolean isShown();
  public final boolean isFlagged();
  public final void show();
  public final void toggleFlag();
}
#endif
