package SameGame.Game.model;

/**
 *
 * @author Nuno
 */
public interface Board_I {

    public int getWidth();
    public int getHeight();
    public int getRemainingBlocks();
    public Block getBlock(int row, int column);
    public boolean addBlock(Block b, int row, int column);
    public Block removeBlock(int row, int column);
    public int removeRow(int row);
    public int removeColumn(int columns);
    public void clear();
    public boolean rotateLeft();
    public boolean rotateRight();
}
