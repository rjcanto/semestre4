package SameGame.Game.model;

import java.util.Iterator;

/**
 *
 * @author Nuno
 */
public interface Board_I {

    public int getWidth();
    public int getHeight();
    public int getRemainingBlocks();
    public boolean isValid(int r, int c);
    public Block getBlock(int row, int column);
    public void addBlock(Block b, int row, int column);
    public Block removeBlock(int row, int column);
    public int removeRow(int row);
    public int removeColumn(int columns);
    public void clear();
    public int select(int r, int c);
    public void unselect();
    public boolean isSelected(int r, int c);
    //public Iterator<Block> getSelectedBlocks();
    public boolean rotate(boolean right);
    public boolean init(String[] blockNames);
}
