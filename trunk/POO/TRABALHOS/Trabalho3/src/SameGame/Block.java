package SameGame;
import java.awt.Color;

/**
 *
 * @author Nuno
 */


public class Block {
    private int type;
    private Color myColor=null;
    private boolean selected=false;

    Block(int type){this.type=type;}
    Block(int type, Color c){this.type=type;myColor=c;}
    public int getType(){return type;}
    public void setColor(Color c){myColor=c;}
    public Color getColor(){return myColor;}
    public void select(){selected=true;}
    public void unselect(){selected=false;}
    public boolean isSelected(){return selected;}
    //protected abstract Color computeColor();
}
