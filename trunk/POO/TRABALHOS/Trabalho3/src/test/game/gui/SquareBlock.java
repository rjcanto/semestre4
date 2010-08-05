/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.Rectangle2D;

/**
 *
 * @author nac
 */
public class SquareBlock extends GameBlock {
    private Rectangle2D.Double object;
    private int width;
    private int height;


    public SquareBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        width=height=SIZE;
        object = new Rectangle2D.Double(posX, posY, width, height);
    }
    public void setSize(int w, int h) {
        height=h;
        width=w;
        object.height=height;
        object.width=width;
    }
    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(getColor());
        g2d.fill(object);
        g2d.draw(object);
    }

    public int getSize() {
        return SIZE;
    }

    public Shape getShape() {
        return object;
    }
}
