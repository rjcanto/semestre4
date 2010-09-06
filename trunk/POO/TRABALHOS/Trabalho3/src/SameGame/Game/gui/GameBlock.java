/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import SameGame.Game.gui.Game_Interfaces.GameShape_I;
import SameGame.Game.model.Block_I;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;


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

    public void unselect() {isSelected=false;}
    public void select() {isSelected=true;}
    public boolean isSelected() {return isSelected;}
    
    public void paintSelection(Graphics2D g2d, Shape object){
        g2d.setStroke(new BasicStroke(10));
        g2d.setColor(Color.DARK_GRAY);
        g2d.draw(object);
        g2d.setStroke(new BasicStroke(0));
    }

}
