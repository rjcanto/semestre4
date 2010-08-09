package SameGame.Game.model;
import java.awt.Color;

/**
 *
 * @author Nuno
 */

public class Block implements Block_I,BlockRule_I, Comparable<Block>{
    private int type;
    private Color myColor=null;
    private boolean selected=false;
    private BlockSelectionRule rule;
    
    Block(int type){this.type=type;}
    Block(int type, Color c){this.type=type;myColor=c;}
    public int getType(){return type;}
    public void setColor(Color c){myColor=c;}
    public Color getColor(){return myColor;}
    public boolean isSelected(){return selected;}
    public void unselect(){this.selected=false;}
    public void select(){this.selected=true;}
    public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}

    public int compareTo(Block b) {
        if (myColor == b.getColor())
            return (type-b.getType());
        return -1;
    }
}
