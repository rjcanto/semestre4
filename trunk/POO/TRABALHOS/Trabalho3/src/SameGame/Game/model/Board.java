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
    private LinkedList<Coordinates> selectedBlocks;
    //private CoordinateList<Coordinates> selectedBlocks;
    
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
    public int getSelectedBlocks(){return selectedBlocks.size();}

    public boolean isValid(int r, int c){return (r>=0 && r<rows && c>=0 && c<columns);}
    public Block getBlock(int r, int c) {return  (isValid(r,c)) ? (grid[r][c]) : null;}
    public Block removeBlock(int r, int c){
        Block aux = getBlock(r,c);
        if (aux == null) return null;
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
                    grid[i][j] = (Block) Class.forName("SameGame.Game.model."+blockNames[rand]).newInstance();
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
    public boolean select(int r, int c) {
        
        boolean[][] rule = getBlock(r,c).getSelectionRule();
        boolean selected = select(r,c,rule);
        if (selected)
            selectAndSave(r,c);
        
        return (selectedBlocks.size()>0)? true:false;
        
    }

    private boolean select(int r, int c, boolean[][] rule){
        Block b = this.removeBlock(r, c);
        /*
         * Verifica canto superior esquerdo
         */
        if (rule[0][0] && c!=0 && r!=0)
            if (rule[1][1]){
                if (b.compareTo(grid[r-1][c-1])==0){
                    this.select(r-1,c-1,rule);
                    selectAndSave(r-1,c-1);
                }
            }else{
                if (grid[r-1][c-1]!=null){
                    this.select(r-1,c-1,rule);
                    selectAndSave(r-1,c-1);
                }
            }

        /*
         * Verifica cima
         */
        if (rule[0][1] && r!=0)
            if (rule[1][1]){
                if (b.compareTo(grid[r-1][c])==0){
                    this.select(r-1,c,rule);
                    selectAndSave(r-1, c);
                }
            }else{
                if (grid[r-1][c]!=null){
                    this.select(r-1,c,rule);
                    selectAndSave(r-1, c);
                }
            }
        /*
         * Verifica canto superior direito
         */
        if (rule[0][2] && c!=columns-1 && r!=0)
            if (rule[1][1]){
                if (b.compareTo(grid[r-1][c+1])==0){
                    this.select(r-1,c+1,rule);
                    selectAndSave(r-1,c+1);
                }
            }else{
                if (grid[r-1][c+1]!=null){
                    this.select(r-1,c+1,rule);
                    selectAndSave(r-1,c+1);
                }
            }
        /*
         * Verifica o lado esquerdo
         */
        if (rule[1][0] && c!=0)
            if (rule[1][1]){
                if (b.compareTo(grid[r][c-1])==0){
                    this.select(r,c-1,rule);
                    selectAndSave(r,c-1);
                }
            }else{
                if (grid[r][c-1]!=null){
                    this.select(r,c-1,rule);
                    selectAndSave(r,c-1);
                }

            }
        /*
         * Verifica o lado direito
         */
        if (rule[1][2] && c!=columns-1)
            if (rule[1][1]){
                if (b.compareTo(grid[r][c+1])==0){
                    this.select(r-1,c+1,rule);
                    selectAndSave(r-1,c+1);
                }
            }else{
                if (grid[r-1][c+1]!=null){
                    this.select(r-1,c+1,rule);
                    selectAndSave(r-1,c+1);
                }
            }
        /*
         * Verifica o canto inferior esquerdo
         */
        if (rule[2][0] && r!=rows-1 && c!=0)
            if (rule[1][1]){
                if (b.compareTo(grid[r+1][c-1])==0){
                    this.select(r+1,c-1,rule);
                    selectAndSave(r+1,c-1);
                }
            }else{
                if (grid[r+1][c-1]!=null){
                    this.select(r+1,c-1,rule);
                    selectAndSave(r+1,c-1);
                }
            }
        /*
         * Verifica baixo
         */
        if (rule[2][1] && r!=rows-1)
            if (rule[1][1]){
                if (b.compareTo(grid[r+1][c])==0){
                    this.select(r+1,c,rule);
                    selectAndSave(r+1,c);
                }
            }else{
                if (grid[r+1][c]!=null){
                    this.select(r+1,c,rule);
                    selectAndSave(r+1,c);
                }
            }
        /*
         * Verifica o canto inferior direito
         */
        if (rule[2][2] && r!= rows-1 && c!=columns-1)
            if (rule[1][1]){
                if (b.compareTo(grid[r+1][c+1])==0){
                    this.select(r+1,c+1,rule);
                    selectAndSave(r+1,c+1);
                }
            }else{
                if (grid[r+1][c+1]!=null){
                    this.select(r+1,c+1,rule);
                    selectAndSave(r+1,c+1);
                }
            }

        addBlock(b, r, c);
        return (selectedBlocks.size()>0)? true:false;
    }

    private void selectAndSave(int r, int c){
        grid[r][c].select();
        selectedBlocks.add(new Coordinates(r,c));
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



