package test.game.model;
import java.awt.Color;

/**
 *
 * @author Nuno
 */


public class Block implements Block_I, BlockRule_I, Comparable<Block>{
    private int type;
    private Color myColor=null;
    private boolean selected=false;
    private BlockSelectionRule rule;

    Block(int type){this.type=type;}
    Block(int type, Color c){this.type=type;myColor=c;}
    public int getType(){return type;}
    public void setColor(Color c){myColor=c;}
    public Color getColor(){return myColor;}
    public void select(){selected=true;}
    public void unselect(){selected=false;}
    public boolean isSelected(){return selected;}
    public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
    public int compareTo(Block o){
        if (this.myColor==o.getColor())
            return this.type-o.getType();
        return -1;
    }



}
