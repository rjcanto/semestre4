/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.Color;
import test.game.model.Block_I;

/**
 *
 * @author nac
 */
public abstract class GameBlock implements GameShape_I,Block_I{
    private Color color;
    private int x;
    private int y;
    private boolean isSelected;

    public GameBlock (Color c, int posX, int posY){
        x = posX;
        y = posY;
        color = c;
        isSelected = false;
    }
    public void setColor(Color c) {color = c;}

    public Color getColor() {return color;}

    public boolean isSelected() {return isSelected;}

    public void unselect() {isSelected=false;}

    public void select() {isSelected=true;}

    public void setPosition(int x, int y) {this.x=x;this.y=y;}

    public int getX() {return x;}

    public int getY() {return y;}

    public void setX(int x) {this.x=x;}

    public void setY(int y) {this.y=y;}

}
