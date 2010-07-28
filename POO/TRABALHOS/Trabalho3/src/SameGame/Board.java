package SameGame;

import java.util.Random;

/**
 *
 * @author Nuno
 */

public class Board implements Board_I{
    private Block[][] grid;
    private int width;
    private int height;
    private int remainingBlocks;

    
    public Board(int width, int height){
        grid = new Block[width][height];
        this.width = width;
        this.height = height;
        remainingBlocks = width*height;
    }
    public int getWidth(){return width;}
    public int getHeight(){return height;}
    public int getRemainingBlocks(){return remainingBlocks;}
    /*public Block[][] getGrid(){return grid;}*/
    
    public Block getBlock(int x, int y) {
        return(grid[x][y]);
    }

    public Block removeBlock(int x, int y){
        Block aux = new Block(grid[x][y].getType(),grid[x][y].getColor());
        grid[x][y]=null;
        --remainingBlocks;
        return aux;
    }
    public boolean addBlock(Block b, int x, int y){
        if (grid[x][y]!=null)
            return false;
        grid[x][y]=b;
        ++remainingBlocks;
        return true;
    }
    public int removeLine(int x){
        int res=0;
        for(int i=0; i<height;++i)
            if (grid[x][i]!=null){
                grid[x][i]=null;
                --remainingBlocks;
                ++res;
            }
        return res;
    }
    public int removeColumn(int y){
        int res=0;
        for(int i=0; i<width;++i)
            if (grid[i][y]!=null){
                grid[i][y]=null;
                --remainingBlocks;
                ++res;
            }
        return res;
    }
    public void clear(){
        for(int x=0;x<height;++x)
            for(int y=0;y<width;++y)
                grid[x][y]=null;
        remainingBlocks=0;
    }

    public void rotateLeft() {
        if (width!=height)
            return;
        Block[][] auxGrid = new Block[width][height];
        for (int x=0;x<height;++x)
            for (int y=0;y<height;++y)
                auxGrid[y][width-x-1]=grid[x][y];
    }

    public void rotateRight() {
        if (width!=height)
            return;      
        Block[][] auxGrid = new Block[width][height];
        for (int x=0;x<height;++x)
            for (int y=0;y<height;++y)
                auxGrid[width-y-1][x]=grid[x][y];
    }
}



