package SameGame.Game.model;
import java.awt.Color;
import java.util.LinkedList;

/**
 *
 * @author Nuno
 */

public class Block {
    private int row=-1;
    private int column=-1;
    private int type;
    private Color myColor=null;
    private boolean selected=false;
    private Board myBoard;

    Block(int type){this.type=type;}
    Block(int type, Color c){this.type=type;myColor=c;}
    Block(int type, Color c, Board b){this.type=type;myColor=c;myBoard=b;}
    public void setCoord(int row, int col){this.row=row;this.column=col;}
    public int getRow(){return row;}
    public int getColumn(){return column;}
    public void setBoard(Board b){myBoard=b;}
    public Board getBoard(){return myBoard;}
    public int getType(){return type;}
    public void setColor(Color c){myColor=c;}
    public Color getColor(){return myColor;}
    public boolean isSelected(){return selected;}
    /* cada tipo de bloco terá as suas regras de selecção em que além de si
     * próprio poderá seleccionar os blocos vizinhos recorrendo ao Board a que
     * pertence. O bloco default apenas se selecciona a si próprio.
     */
    public void unselect(){this.selected=false;}
    public void select(){this.selected=true;}
    public LinkedList<Block> selectGroup(LinkedList<Block> list){
        this.select();
        list.add(this);
        return list;
    }
}
