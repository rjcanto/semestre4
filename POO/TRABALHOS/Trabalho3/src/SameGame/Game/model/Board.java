package SameGame.Game.model;

import java.util.Iterator;
import java.util.LinkedList;
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
    private LinkedList selectedBlocks;
    //private CoordinateList<Coordinates> selectedBlocks;
    
    public class Coordinates{
        private int row;
        private int column;
        public Coordinates(int r, int c){row=r;column=c;}
        public int getRow(){return row;}
        public int getColumn(){return column;}
    }

    public Board(int height, int width, String[] blockNames){
        grid = new Block[height][width];
        this.columns = width;
        this.rows = height;
        remainingBlocks = 0;
        selectedBlocks= new LinkedList();
        this.init(blockNames);
    }

    public int getWidth(){return columns;}
    public int getHeight(){return rows;}
    public int getRemainingBlocks(){return remainingBlocks;}

    public boolean isValid(int r, int c){return (r>=0 && r<rows && c>=0 && c<columns);}
    public Block getBlock(int r, int c) {
        if (isValid(r,c))
            return(grid[r][c]);
        return null;
    }
    public Block removeBlock(int r, int c){
        if (!isValid(r,c) || grid[r][c]==null)
            return null;
        Block aux = grid[r][c];
        grid[r][c]=null;
        --remainingBlocks;
        return aux;
    }
    public void addBlock(Block b, int r, int c){
        if (!isValid(r,c)) return;
        if (grid[r][c]==null)
            ++remainingBlocks;
        grid[r][c]=b;
    }
    public int removeRow(int r){
        if (!isValid(r,0)) return 0;
        int res=remainingBlocks;
        for(int i=0; i<columns;++i)
            if (grid[r][i]!=null){
                grid[r][i]=null;
                --remainingBlocks;
            }
        return res-remainingBlocks;
    }
    public int removeColumn(int c){
        if (!isValid(0,c)) return 0;
        int res=remainingBlocks;
        for(int i=0; i<rows;++i)
            if (grid[i][c]!=null){
                grid[i][c]=null;
                --remainingBlocks;
            }
        return res-remainingBlocks;
    }
    public void clear(){
        if (remainingBlocks==0) return;
        for(int x=0;x<rows;++x)
            for(int y=0;y<columns;++y)
                grid[x][y]=null;
        remainingBlocks=0;
    }


    /*
     * Métodos para manipulação do Board
     */
    public boolean rotate(boolean right) {
        if (rows!=columns || remainingBlocks==0)
            return false;
        Block[][] auxGrid = new Block[columns][rows];

        int myRow,myCol;
        int size = columns - 1;

        for (int row=0;row<rows;++row)
            for (int col=0;col<columns;++col){
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
        if (remainingBlocks==0) return;
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
        if (remainingBlocks==0) return;
        int c, c1, r;
        for (r=0; r<rows; ++c){
            c=0;c1=1;
            while(c<columns && c1<=columns){
                if (grid[r][c]!=null){
                    ++c;++c1;
                }else{
                    while (c1<=columns && grid[r][c1]==null)
                        ++c1;
                    if (c1>columns) break;
                    grid[r][c]=grid[r][c1];
                    grid[r][c1]=null;
                    ++c;++c1;
                }
            }
        }
    }

    /*
     * Inicialização do Board.
     */
    public final boolean init(String[] blockNames) {
        int rand;
        for (int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                rand = new Random().nextInt(blockNames.length);
                try{
                    grid[i][j] = (Block) Class.forName(blockNames[rand]).newInstance();
                    ++remainingBlocks;
                        //Class.forName(string+"Block").newInstance();
                } catch(Exception e){
                    System.err.print("Classe para criar o bloco " +blockNames[rand]+ "não foi encontrada.");
                    return false;
                }
            }
        }
        return true;
    }
    
    /*
     *Métodos para selecção de blocos
     */
    public int select(int r, int c) {
        Block b = this.removeBlock(r, c);
        boolean[][] rule = b.getSelectionRule();

        if (rule[0][0])
            if (b.compareTo(grid[r-1][c-1])==0){

            }




        




        



        return selectedBlocks.size();
    }

//    public Iterator<Block> getSelectedBlocks() {
//        throw new UnsupportedOperationException("Not supported yet.");
//    }

    public void unselect(){
        Iterator<Coordinates> it = selectedBlocks.iterator();
        Coordinates c;
        while (it.hasNext()){
            c = it.next();
            grid[c.getRow()][c.getColumn()].unselect();
            selectedBlocks.remove();
        }
    }
    public void unselect(int r, int c){
        Coordinates coord = new Coordinates(r,c);
        if (!grid[r][c].isSelected())
            return;
        Iterator<Coordinates> it = selectedBlocks.iterator();
        Coordinates aux;
        while (it.hasNext()){
            aux = it.next();
            if (aux.equals(coord)){
                grid[coord.getRow()][coord.getColumn()].unselect();
                selectedBlocks.remove();
            }
        }
    }

    public boolean isSelected(int r, int c) {
        return grid[r][c].isSelected();
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



