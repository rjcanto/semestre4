/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui.BlockShapes;

import java.awt.Color;
import java.awt.Shape;
import test.game.gui.Game_Interfaces.GameShape_I;
import test.game.model.Block_I;

/**
 *
 * @author nac
 */
public abstract class GameBlock implements GameShape_I,Block_I{
    private Color color;
    private int x;
    private int y;
    private int width;
    private int height;
    private boolean isSelected;

    public GameBlock (Color c, int posX, int posY){
        this(c,posX, posY, SIZE,SIZE);
    }
    public GameBlock (Color c, int posX, int posY, int width, int height){
        this.width = width;
        this.height = height;
        x = posX*width;
        y = posY*height;
        color = c;
        isSelected = false;
    }

    public void setColor(Color c) {color = c;}
    public void setPosition(int x, int y) {this.x=x;this.y=y;}
    public void setWidth(int w){width= w;}
    public void setHeight(int h){height = h;}
    public void setX(int x) {this.x=x*width;}
    public void setY(int y) {this.y=y*height;}
    public void setSize(int width, int height){this.width = width;this.height = height;}
    public Color getColor() {return color;}
    public int getX() {return x;}
    public int getY() {return y;}
    public int getWidth(){return width;}
    public int getHeight(){return height;}

    public abstract Shape getShape();

    public void unselect() {isSelected=false;}
    public void select() {isSelected=true;}
    public boolean isSelected() {return isSelected;}
    




}
