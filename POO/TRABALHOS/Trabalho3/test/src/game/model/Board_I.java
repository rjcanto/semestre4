package test.game.model;

/**
 *
 * @author nac
 */
public interface Board_I {

    public int getWidth();
    public int getHeight();
    public int getRemainingBlocks();
    public Block getBlock(int x, int y);
    public boolean addBlock(Block b, int x, int y);
    public Block removeBlock(int x, int y);
    public int removeLine(int x);
    public int removeColumn(int y);
    public void clear();
    public void rotateLeft();
    public void rotateRight();
}
