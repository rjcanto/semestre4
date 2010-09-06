package SameGame.Game.model;

/**
 *
 * @author Nuno
 */
public class UndoInfo {
    private Block[][] grid;
    private int score;
    private int remainningBlocks;

    public UndoInfo(Block[][] grid, int score, int remainningBlocks){
        this.grid = new Block[grid.length][grid[0].length];
        for (int r=0; r<this.grid.length; ++r)
            for (int c=0; c<this.grid[0].length;++c)
                this.grid[c][r]=grid[r][c];

        this.score = score;
        this.remainningBlocks = remainningBlocks;
    }
    public int getScore(){return score;}
    public int getRemainningBlocks(){return remainningBlocks;}
    public Block getBlock(int r, int c){return grid[r][c];}
}
