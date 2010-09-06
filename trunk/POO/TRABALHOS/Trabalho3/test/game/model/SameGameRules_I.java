package test.game;

/**
 *
 * @author Nuno
 */
public interface SameGameRules_I {
    public boolean selectBlock(int x, int y);
    public boolean removeBlock(int x, int y);
    public boolean addNewColumn();
    public boolean shiftDown();
    public boolean shiftLeft();
}
