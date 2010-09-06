package SameGame.Game.model;

import java.awt.Color;

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
    public boolean addBlock(Block b, int row, int column);
    public boolean addBlock(String name, int type, int row, int column);
    public boolean addBlock(String name, int type, int colorID, int row, int column);
    public Block removeBlock(int row, int column);
    public int removeRow(int row);
    public int removeColumn(int columns);
    public void clear();
    public boolean select(int r, int c);
    public void unselect();
    public boolean isSelected(int r, int c);
    //public Iterator<Block> getSelectedBlocks();
    public boolean rotate(boolean right);
    public void initBoard();
}
