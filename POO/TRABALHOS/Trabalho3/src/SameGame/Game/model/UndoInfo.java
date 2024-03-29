/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.model;


public class UndoInfo {
    private Block[][] grid;
    private int score;
    private int remainningBlocks;
    private int rotateLimit;

    public UndoInfo(Block[][] grid, int score, int remainningBlocks, int rotateLimit){
        this.grid = new Block[grid.length][grid[0].length];
        for (int r=0; r<this.grid.length; ++r)
            for (int c=0; c<this.grid[0].length;++c)
                this.grid[r][c]=grid[r][c];

        this.score = score;
        this.remainningBlocks = remainningBlocks;
        this.rotateLimit = rotateLimit;
    }
    public int getScore(){return score;}
    public int getRemainningBlocks(){return remainningBlocks;}
    public Block getBlock(int r, int c){return grid[r][c];}
    public int getRotateLimit(){return rotateLimit;}
}
