package SameGame.Game.model;

import java.util.Random;

/**
 *
 * @author Nuno
 */

public class Board implements Board_I{
    private Block[][] grid;
    private int rows;
    private int columns;
    private int remainingBlocks;

    
    public Board(int height, int width){
        grid = new Block[height][width];
        this.columns = width;
        this.rows = height;
        remainingBlocks = width*height;
    }
    public int getWidth(){return columns;}
    public int getHeight(){return rows;}
    public int getRemainingBlocks(){return remainingBlocks;}
    /*public Block[][] getGrid(){return grid;}*/
    
    public Block getBlock(int r, int c) {
        return(grid[r][c]);
    }

    public Block removeBlock(int r, int c){
        if (grid[r][c]==null) return null;
        Block aux = new Block(grid[r][c].getType(),grid[r][c].getColor());
        grid[r][c]=null;
        --remainingBlocks;
        return aux;
    }
    public Block removeBlock(Block b){
        if (b.getRow()<0 || b.getColumn()<0)
            return null;
        return removeBlock(b.getRow(),b.getColumn());
    }
    
    public boolean addBlock(Block b, int r, int c){
        //if (grid[x][y]!=null)
        //    return false;
        b.setCoord(r, c);
        grid[r][c]=b;
        ++remainingBlocks;
        return true;
    }

    public boolean addBlock(Block b){
        if (b.getRow()<0 || b.getColumn()<0)
            return false;
        return addBlock(b,b.getRow(),b.getColumn());
    }
    public int removeRow(int r){
        int res=0;
        for(int i=0; i<columns;++i)
            if (grid[r][i]!=null){
                grid[r][i]=null;
                --remainingBlocks;
                ++res;
            }
        return res;
    }
    public int removeColumn(int c){
        int res=0;
        for(int i=0; i<rows;++i)
            if (grid[i][c]!=null){
                grid[i][c]=null;
                --remainingBlocks;
                ++res;
            }
        return res;
    }
    public void clear(){
        for(int x=0;x<rows;++x)
            for(int y=0;y<columns;++y)
                grid[x][y]=null;
        remainingBlocks=0;
    }

    public boolean rotateRight() {
        if (rows!=columns)
            return false;
        Block[][] auxGrid = new Block[columns][rows];
        for (int x=0;x<rows;++x)
            for (int y=0;y<rows;++y)
                auxGrid[y][columns-x-1]=grid[x][y];
        grid=auxGrid;
        return true;
    }

    public boolean rotateLeft() {
        if (rows!=columns)
            return false;
        Block[][] auxGrid = new Block[columns][rows];
        for (int x=0;x<rows;++x)
            for (int y=0;y<rows;++y)
                auxGrid[columns-y-1][x]=grid[x][y];
        grid=auxGrid;
        return true;
    }

    public boolean rotate(boolean right) {
        if (rows!=columns)
            return false;
        Block[][] auxGrid = new Block[columns][rows];

        int myRow,myCol;
        int size = columns - 1;

        for (int row=0;row<rows;++row)
            for (int col=0;col<columns;++col){

            //Right --> auxGrid[y][columns-x-1]=grid[x][y];
            //Left  --> auxGrid[columns-y-1][x]=grid[x][y];

                if (right){
                    myRow=size - col;
                    myCol= row;
                }else{
                    myRow=col;
                    myCol=size - row;
                }
            auxGrid[row][col]=grid[myRow][myCol];
        }
        grid=auxGrid;
        return true;
    }


    public void shiftDown() {
        int r, r1, c;
        for (c=0; c<columns; ++c){
            r=rows-1;r1=rows-2;
            while(r>0 && r1>=0){
                if (grid[r][c]!=null){
                    --r;--r1;
                }else{
                    while (r1>=0 && grid[r1][c]==null)
                        --r1;
                    if (r1<0) break;
                    grid[r][c]=grid[r1][c];
                    grid[r1][c]=null;
                    --r;--r1;
                }
            }
        }
    }
    public void shiftLeft(){



    }

    @Override
    public String toString(){
        String res="";
        for (int i=0; i<rows;++i){
            for (int j=0; j<columns;++j)
                res+=grid[i][j]==null? "-:- | ":grid[i][j].getType()+ ":" +grid[i][j].isSelected() + " | ";
            res+='\n';
        }
        return res;
    }

    /*DEBUG*/
    private String gridToString(Block[][] g){
        String res="";
        for (int i=0; i<g.length;++i){
            for (int j=0; j<g[0].length;++j)
                res+=g[i][j]==null? "-:- | ":g[i][j].getType()+ ":" +g[i][j].isSelected() + " | ";
            res+='\n';
        }
        return res;



    }

}



