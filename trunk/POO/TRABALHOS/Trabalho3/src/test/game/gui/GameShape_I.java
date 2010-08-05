/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Shape;

/**
 *
 * @author nac
 */
public interface GameShape_I {
    public final int SIZE=50;
    public void setPosition(int x, int y);
    public void setColor(Color color);
    public int getSize();
    public Color getColor();
    public Shape getShape();
    public void paintShape(Graphics g);
    public int getX();
    public int getY();
    public void setX(int x);
    public void setY(int y);
}

