package SameGame.Game.model;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;


/**
 *
 * @author Nuno
 */

public class Board implements Board_I, GameModelVars_I{
    private Block[][] grid;
    private int rows;
    private int columns;
    private int remainingBlocks;
    private LinkedList<Coordinates> selectedBlocks;
    private UndoInfo[] undoData;
    private int undoLevel;
    //private CoordinateList<Coordinates> selectedBlocks;
    
    public Board(int height, int width, String[] blockNames){
        grid = new Block[height][width];
        this.columns = width;
        this.rows = height;
        remainingBlocks = 0;
        /*  normalmente, o número máximo de jogadas será 
         *  metade do número total de blocos */
        undoData = new UndoInfo[height*width/2];
        undoLevel=0;
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
     * verifica se o board tem alguma coluna vazia
     * @return retorna indice da primeira coluna vazia ou numero de colunas se nenhuma
     */
    public int checkEmptyColumn(){
        for (int i=0;i<columns;++i)
            if (grid[rows-1][i]==null)
                return i;
        return -1;
    }

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
     * Desloca todos os blocos da coluna col até ao fim da grelha uma coluna para
     * a esquerda.
     * @param col coluna de destino para onde se vai shiftar os blocos
     */
    public void shitfLeftOne(int col){
        for (int c=col; c<columns; ++c)
            for (int r=rows-1;r>0;--r)
                if (grid[r][c]==null && grid[r][c+1]!=null)
                    addBlock(removeBlock(r, c+1), r, c);
    }

    /*
     * Inicialização do Board.
     */
    public final boolean init(String[] blockNames) {
        int rand;
        for (int r = 0; r < rows; ++r){
            for(int c = 0; c < columns; ++c){
                rand = new Random().nextInt(blockNames.length);
                try{
                    grid[r][c] = (Block) Class.forName("SameGame.Game.model."+blockNames[rand]).newInstance();
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
     * Adiciona uma nova coluna de blocos na ultima coluna do board e "encosta"
     * os blocos ao mais próximo deste para a direita. Caso a linha esteja vazia
     * após chegar à primeira coluna faz o "shiftDown"
     * @param blockNames Array de strings com o nome das classes a serem usadas
     *                   na criação dos blocos.
     */
    public void addColumnToEnd(String[] blockNames){
        int rand;
        for(int r = 0; r < rows; ++r){
            rand = new Random().nextInt(blockNames.length);
            try{
                grid[r][columns-1] = (Block) Class.forName("SameGame.Game.model."+blockNames[rand]).newInstance();
                ++remainingBlocks;
                    //Class.forName(string+"Block").newInstance();
            } catch(Exception e){
                System.err.print("Classe para criar o bloco " +blockNames[rand]+ "não foi encontrada.");
            }
        }
        for(int r = 0; r < rows; ++r){
            int c= columns-2;
            while (c>=0 && grid[r][c]==null)
                c--;
            if (c!=columns-2)
                addBlock(removeBlock(r, columns-1), r, c+1);
        }
        this.shiftDown();
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
        return (selectedBlocks.size()>0)? true:false;
    }

    private void checkBlock(int r, int c, boolean[][] rule, Block b){
        if (!isValid(r, c)) return;
        if (rule[1][1]){
            if (grid[r][c]!=null && b.compareTo(grid[r][c])==0){
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

    public void unselect(){
        if (selectedBlocks.size()==0)
            return;
        Iterator<Coordinates> it = selectedBlocks.iterator();
        Coordinates c;
        while (it.hasNext()){
            c = it.next();
            grid[c.getRow()][c.getColumn()].unselect();
            it.remove();
        }
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
            it.remove();
        }
        return result;
    }

    public boolean isSelected(int r, int c) {
        return grid[r][c].isSelected();
    }

    /*
     * Métodos para gravação de estado para possibilitar Undo
     */
    public void saveState(int score){
        undoData[undoLevel++]= new UndoInfo(grid, score, remainingBlocks);
    }
    public int loadLastState(){
        if (undoLevel<=0) return 0;
        return loadState(undoLevel--);
    }
    public int loadState(int l){
        if (l<0 || l>undoLevel) return 0;
        
        for (int r=0; r<rows; ++r)
            for (int c=0; c<columns; ++c)
                addBlock(undoData[l].getBlock(r, c), r, c);

        remainingBlocks = undoData[l].getRemainningBlocks();
        //para libertar espaço dos UndoInfo que deixaram de fazer sentido
        for (int k=l;k<undoLevel;++k) undoData[k]=null;
        undoLevel = l-1;
        return undoData[undoLevel].getScore();
    }

    @Override
    public String toString(){
        String res="";
        for (int i=0; i<rows;++i){
            for (int j=0; j<columns;++j)
                res+=grid[i][j]==null? "-:- | ":grid[i][j].getType()+ ":"+grid[i][j].getColor().getRGB()+ ":" +grid[i][j].isSelected() + " | ";
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



