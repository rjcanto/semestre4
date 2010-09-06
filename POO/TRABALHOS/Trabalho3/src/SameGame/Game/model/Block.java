package SameGame.Game.model;

import java.awt.Color;

/**
 *
 * @author Nuno
 */

public abstract class Block implements Block_I,BlockRule_I, Comparable<Block>{
    private int type;
    private Color myColor=null;
    private boolean selected=false;
    private BlockSelectionRule rule;
    private int radius;

    public Block(int type){this.type=type;}
    public Block(int type, Color c){this.type=type;myColor=c;}
    public Block(int type, int radius){this.type=type; this.radius=radius;}
    public Block(int type, Color c, int radius){this.type=type;myColor=c;this.radius=radius;}
    public int getRadius(){return radius;}
    public void setRadius(int radius){this.radius=radius;}
    public void setType(int type){this.type=type;}
    public int getType(){return type;}
    public void setColor(Color c){myColor=c;}
    public Color getColor(){return myColor;}
    public boolean isSelected(){return selected;}
    public void unselect(){this.selected=false;}
    public void select(){this.selected=true;}
    public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
    @Override
    public abstract String toString();
    public int compareTo(Block b) {
        if (myColor == b.getColor())
            return (type-b.getType());
        return -1;
    }
    public abstract String toStringDebug();
}
