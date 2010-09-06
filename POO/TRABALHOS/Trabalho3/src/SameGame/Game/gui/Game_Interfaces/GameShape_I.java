/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui.Game_Interfaces;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Shape;

/**
 *
 * @author nac
 */
public interface GameShape_I {
    public final int SIZE=50;
    public void setColor(Color c);
    public void setPosition(int x, int y);
    public void setWidth(int w);
    public void setHeight(int h);
    public void setX(int x);
    public void setY(int y);
    public void setSize(int width, int height);
    public Color getColor();
    public int getX();
    public int getY();
    public int getWidth();
    public int getHeight();
    public void unselect();
    public void select();
    public boolean isSelected();
    public void paintShape(Graphics g);
    public Shape getShape();
}

