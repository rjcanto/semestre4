
public abstract class Cell {
  protected abstract char getView();
  public abstract void touch();
  public boolean isBomb() { return false; }

  private enum Stat {
	NONE('*'), FLAG('X'), VIEW(' ');
	public char view;
	Stat(char v) { view=v; }
  }
  Stat stat=Stat.NONE;

  public final void print()        { System.out.print( stat==Stat.VIEW ? getView() : stat.view); } 
  public final boolean isShown()   { return stat==Stat.VIEW; }
  public final boolean isFlagged() { return stat==Stat.FLAG; }
  public final void show()         { stat=Stat.VIEW; }
  public final void toggleFlag()   { 
	  if (stat== Stat.FLAG) stat=Stat.NONE;
	  else
      if (stat== Stat.NONE) stat=Stat.FLAG;
  }
}
