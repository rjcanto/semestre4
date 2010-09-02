package SameGame.Game.model;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Nuno
 */

public class Board implements Board_I, GameModelVars_I{
    private Block[][] grid;
    private int rows;
    private int columns;
    private int remainingBlocks;
    private String[] blockNames;
    private int blockQtyLimit[];
    private int blockQtyLeft[];
    private LinkedList<Coordinates> selectedBlocks;
    private LinkedList<SavedState> undoData;
    
    public Board(int height, int width, String[] blockNames, int[] blockQtyLimit, boolean init){
        grid = new Block[height][width];
        this.columns = width;
        this.rows = height;
        remainingBlocks = 0;
        undoData = new LinkedList<SavedState>();
        selectedBlocks= new LinkedList<Coordinates>();
        this.blockNames=blockNames;
        if (blockQtyLimit==null)
            defaultBlockQtyLimit();
        else
            this.blockQtyLimit= blockQtyLimit;
        resetBlockQtyLeft();
        if (init) this.init();
    }

    public int getWidth(){return columns;}
    public int getHeight(){return rows;}
    public int getRemainingBlocks(){return remainingBlocks;}
    public int getNumberSelectedBlocks(){return selectedBlocks.size();}
    public String[] getBlockNames() {return blockNames;}
    public void setBlockNames(String[] blockNames) {this.blockNames = blockNames;}

    public boolean isValid(int r, int c){return (r>=0 && r<rows && c>=0 && c<columns);}
    public Block getBlock(int r, int c) {return  (isValid(r,c)) ? (grid[r][c]) : null;}
    public Block removeBlock(int r, int c){
        Block aux = getBlock(r,c);
        if (aux == null) return null;
        grid[r][c]=null;
        --remainingBlocks;
        ++blockQtyLeft[aux.getType()];
        return aux;
    }
    public boolean addBlock(Block b, int r, int c){
        if (!isValid(r,c)) return false;
        if (grid[r][c]==null){
            ++remainingBlocks;
        }
        grid[r][c]=b;
        --blockQtyLeft[b.getType()];
        return true;
    }
    public boolean addBlock(String name, int type, int r, int c){
        if (!isValid(r,c)) return false;
        if (grid[r][c]==null)
            ++remainingBlocks;
        try{
            grid[r][c] = (Block) Class.forName("SameGame.Game.model.blocks."+name).
                    getDeclaredConstructor(int.class).newInstance(type);
        } catch(Exception ex){
            Logger.getLogger(Board.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            --remainingBlocks;
            return false;
        }
        --blockQtyLeft[type];
        return true;
    }
    public boolean addBlock(String name, int type, int colorID, int r, int c){
        if (!isValid(r,c)) return false;
        if (grid[r][c]==null)
            ++remainingBlocks;
        try{
            grid[r][c] = (Block) Class.forName("SameGame.Game.model.blocks."+name).
                    getDeclaredConstructor(int.class, int.class).newInstance(type, colorID);
        } catch(Exception ex){
            Logger.getLogger(Board.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            --remainingBlocks;
            return false;
        }
        --blockQtyLeft[type];
        return true;
    }

    public int removeRow(int r){
        if (!isValid(r,0)) return 0;
        int res=remainingBlocks;
        for(int i=0; i<columns;++i)
            if (grid[r][i]!=null){
                ++blockQtyLeft[grid[r][i].getType()];
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
                ++blockQtyLeft[grid[i][c].getType()];
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
        resetBlockQtyLeft();
    }

    /*
     * verifica se o board tem alguma coluna vazia (linha de baixo com espaços)
     * e move todos os blocos à sua direita para que as coluna vazias fiquem
     * do lado direito
     * 
     */
    public boolean removeEmptyColumns(){
        boolean res=false;
        int colOrig=0, colDest=0;
        //procura primeira coluna vazia
        while (colDest<columns && grid[rows-1][colDest++]!=null){}
        //vamos verificar qual a primeira coluna preenchida após a coluna vazia
        //se não existirem colunas vazia, colOrig ultrapassa tb os limites
        colOrig=colDest;
        while (colOrig<columns && grid[rows-1][colOrig++]==null){res = true;}
        //move as colunas à esquerda para os espaços vazios, colOrig>=colDest
        for ( ; colOrig<columns; ++colOrig, ++colDest)
            for (int r=rows ;r>=0 ;--r){
                if (grid[r][colOrig]!=null)
                    break;
                addBlock(removeBlock(r,colOrig),r, colDest);
            }
        return res;
    }
    /*
     * Adiciona uma nova coluna de blocos na linha col
     * @param blockNames Array de strings com o nome das classes a serem usadas
     *                   na criação dos blocos.
     */
    public void addColumn(int col){
        int rand;
        for(int r = 0; r < rows; ++r){
            rand = (new Random().nextInt(blockNames.length))*71%blockNames.length;
            while (blockQtyLeft[rand]<=0)
                rand = (new Random().nextInt(blockNames.length))*71%blockNames.length;
            while (!addBlock(blockNames[rand], rand, r, col)){
                removeBlockName(rand);
            }
        }
    }
    /*
    private int getRandomBlockNameID(){




    }
*/

    public void fillEmptyColumns(boolean shift) {
        int c= columns;
        while(c>=0 && grid[rows-1][c]==null){
            addColumn(c);
            if (shift){
                shiftLeft();
                shiftDown();
            }else{
                --c;
            }
        }
    }
    /*
     * Métodos usados para ser possível limitar o número máximo de blocos de um
     * determinado tipo que podem aparecer no board ao mesmo tempo.
     * Ao usar blocos com características especiais, podemos querer limitar o
     * número máximo destes blocos para evitar tornar o jogo demasiado fácil
     */
    /*
     * Por defeito cada tipo de bloco poderá ter até remainingBlocks blocos
     */
    private void defaultBlockQtyLimit(){
        blockQtyLimit = new int[blockNames.length];
        for (int i=0; i<blockQtyLimit.length;++i)
            blockQtyLimit[i]=rows*columns;
    }
    private void resetBlockQtyLeft(){
        blockQtyLeft = new int[blockQtyLimit.length];
        System.arraycopy(blockQtyLimit, 0, blockQtyLeft, 0, blockQtyLimit.length);}
        
    /*
     * Métodos para manipulação da Grelha
     */
    /*
     * Roda o tabuleiro de jogo
     * @param right se true roda para a direita, se false para a esquerda
     * @return boolean true se foi possível rodar, false se falhou
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
    public final void init() {
        this.clear();
        for (int c = 0; c < rows; ++c)
            addColumn(c);
    }


    private void removeBlockName(int idx) {
        if (blockNames.length==1) {
            Logger.getLogger(Board.class.getName()).log(Level.SEVERE,
                    "Not able to access Block Classes.");
            System.exit(1);
        }
        String[] aux = new String[blockNames.length-1];
        System.arraycopy(blockNames, 0, aux, 0, idx);
        System.arraycopy(blockNames, idx+1, aux, 0, aux.length-idx);
    }



    /*
     *Métodos para seleccionar blocos, consultar selecção e remover seleccionados
     */
    public boolean select(int r, int c) {
        if (!isValid(r, c)) return false;
        boolean[][] rule = getBlock(r,c).getSelectionRule();
        boolean selected = select(r,c,rule);
        if (selected){
            grid[r][c].select();
            selectedBlocks.add(new Coordinates(r,c));
        }
        return (selectedBlocks.size()>0)? true:false;
    }

    /*
     * Método para seleccionar recursivamente blocos de acordo com as rules
     * passadas e até à distância radius.
     * No final do mesmo os blocos terao a propriedade selected a true e foram
     * adicionados à lista SelectedBlocks
     * 
     * @param r linha a que pertence o bloco a seleccionar
     * @param c coluna a que pertence o bloco a seleccionar
     * @param rule variável com as regras de selecção a utilizar
     * @param radius distância até à qual deve ser efectuada a selecção
     * @return retorna true se foi efectuada alguma selecção ou false no caso
     *          contrário
     */
    private boolean select(int r, int c, boolean[][] rule){
        Block b = this.removeBlock(r, c);
        for (int i=0; i<rule.length;++i)
            for (int j=0; j<rule[0].length;++j){
                if (rule[i][j] && isValid(r + (i - 1) , c + (j - 1)))
                    checkBlock(r + (i - 1) , c + (j - 1), rule, b);
        }
        addBlock(b, r, c);
        return (selectedBlocks.size()>0);
    }

    private void checkBlock(int r, int c, boolean[][] rule, Block b){
        if (!isValid(r, c)) return;
        if (grid[r][c]!=null){
            if (rule[1][1]){
                if (b.compareTo(grid[r][c])==0){
                    this.select(r,c,rule);
                    grid[r][c].select();
                    selectedBlocks.add(new Coordinates(r,c));
                }
            }else if (grid[r][c]!=null){
                    this.select(r,c,rule);
                    grid[r][c].select();
                    selectedBlocks.add(new Coordinates(r,c));
            }
        }
    }

    public void unselect(){
        if (selectedBlocks.size()==0)
            return;
        Iterator<Coordinates> it = selectedBlocks.iterator();
        Coordinates c;
        while (it.hasNext()){
            c = it.next();
            grid[c.getRow()][c.getColumn()].unselect();
        }
        selectedBlocks.clear();
    }
    public void unselect(int r, int c){
        if (!grid[r][c].isSelected())
            return;
        this.unselect();
    }
    public int removeSelected(){
        int result = selectedBlocks.size();
        if (result==0)
            return 0;
        Iterator<Coordinates> it = selectedBlocks.iterator();
        Coordinates c;
        while (it.hasNext()){
            c = it.next();
            this.removeBlock(c.getRow(),c.getColumn());
        }
        selectedBlocks.clear();
        return result;
    }

    public boolean isSelected(int r, int c) {
        return grid[r][c].isSelected();
    }

    /*
     * Métodos para gravação de estado para possibilitar Undo
     * Não permite efectuar o redo
     */
    public void saveState(int score){
        undoData.addFirst(new SavedState(grid, score, remainingBlocks));
    }
    
    public int loadState(){
        if (undoData.isEmpty()) return 0;
        SavedState ss = undoData.removeFirst();
        for (int r=0; r<rows; ++r)
            for (int c=0; c<columns; ++c)
                addBlock(ss.getBlock(r, c), r, c);
        remainingBlocks = ss.getRemainningBlocks();
        return ss.getScore();
    }



    @Override
    public String toString(){
        String res="";
        for (int i=0; i<rows;++i){
            for (int j=0; j<columns;++j)
                res+=grid[i][j]==null? " ; ;":grid[i][j].toString();
            res+='\n';
        }
        return res;
    }

    public String toStringDebug(){
        String res="";
        for (int i=0; i<rows;++i){
            for (int j=0; j<columns;++j)
                res+=grid[i][j]==null? "   - -     ||":grid[i][j].toStringDebug()+((grid[i][j].isSelected())? "true ": "false")+"||";
            res+='\n';
        }
        return res;
    }


}



