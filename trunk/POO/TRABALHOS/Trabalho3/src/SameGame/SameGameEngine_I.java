package SameGame;
/**
 *
 * @author Nuno
 */
public interface SameGameEngine_I {
    public void setGameType(int type);
    public void setContinuity(boolean cont);
    public boolean selectBlock(int x, int y);
    public boolean unselectBlock(int x, int y);
    public boolean unselectBlock(Block block);
    public int removeSelectedBlock();
    public int removeBlock(int x, int y);
    public int removeBlock(Block block);
    public void newGame();
}
