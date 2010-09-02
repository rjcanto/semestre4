package test.game.model;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author nac
 */

public class Board implements Board_I{
    private Block[][] grid;
    private int width;
    private int height;
    private int remainingBlocks;
    private final String[] blockInstances ={"RGB","YM","B","W"};

    
        public Board(int width, int height){
        grid = new Block[width][height];
        this.width = width;
        this.height = height;
        remainingBlocks = width*height;
        initBoard();
    }
    interface getBlockNI{ Block generalMethod();}
    private void initBoard(){
        getBlockNI[] ni = {
            new getBlockNI() {public Block generalMethod() {return new RGBBlock();}},
            new getBlockNI() {public Block generalMethod() {return new YMBlock();}},
            new getBlockNI() {public Block generalMethod() {return new BBlock();}},
            new getBlockNI() {public Block generalMethod() {return new WBlock();}}
        };
        int rand;
        boolean found= false;
        int[] count = {10,20,25};

        for (int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                rand = new Random().nextInt(ni.length);
                grid[i][j] = ni[rand].generalMethod();
                
/*                found=false;
                
                while(!found){
                    switch (rand){
                        case 0:
                            grid[i][j] = new RGBBlock();
                            found=true;
                            break;
                        case 1:
                            if ( count[2] == 0 ){++rand; break;}
                                grid[i][j] = new YMBlock();
                                found=true;
                                --count[2];
                            break;
                        case 2:
                            if ( count[1] == 0 ){++rand; break;}
                                grid[i][j] = new BBlock();
                                found=true;
                                --count[1];
                            break;
                        default:
                            if ( count[0] == 0 ) {rand=0; break;};
                                grid[i][j] = new WBlock();
                                found=true;
                                --count[0];
                            break;
                    }
                    
                }*/
            }
        }
    }
		
    public int getWidth(){return width;}
    public int getHeight(){return height;}
    public int getRemainingBlocks(){return remainingBlocks;}
    /*public Block[][] getGrid(){return grid;}*/

    public void moveBlockDown(int x, int y){
        grid[x][y] = null;
        if (y-1 >= 0){
            grid[x][y] = grid[x][y-1];
            moveBlockDown(x, y-1);
        }
    }
    public void moveBlockRight(int x, int y){
        grid[x][y] = null;
        if (x-1 >= 0){
            grid[x][y] = grid[x-1][y];
            moveBlockDown(x-1, y);
        }
    }

    public void moveBlock(int x, int y){
        if (x < 0 || y < 0 ) return;
        /*if (x == 0 || y == 0) {grid[x][y]=null; return;}*/
        moveBlockDown(x, y);
        if (grid[x][y] == null) moveBlockRight(x, y);
    }
    public Block getBlock(int x, int y) {
        return(grid[x][y]);
    }

    public Block removeBlock(int x, int y){
        if (grid[x][y] == null) return null;
        Block aux = new Block(grid[x][y].getType(),grid[x][y].getColor());
        grid[x][y]=null;
        --remainingBlocks;
        moveBlock(x, y);
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
        for(int y=0; y<height;++y)
            if (grid[x][y]!=null){
                grid[x][y]=null;
                --remainingBlocks;
                ++res;
            }
        return res;
    }
    public int removeColumn(int y){
        int res=0;
        for(int x=0; x<width;++x)
            if (grid[x][y]!=null){
                grid[x][y]=null;
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

    public void print(){
        for (int y=0;y<height;++y){
            for (int x=0;x<width;++x){
                System.out.format("  %c  |",(grid[x][y] != null)?'0'+(char)grid[x][y].getType():' ');
            }
            System.out.println("");
        }
    }
}



