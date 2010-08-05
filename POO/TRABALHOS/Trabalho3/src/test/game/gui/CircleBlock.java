/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;

/**
 *
 * @author nac
 */
public class CircleBlock extends GameBlock {
    private Ellipse2D.Double object;
    private Ellipse2D.Double center;
    private int width;
    private int height;

    public CircleBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        width=height=SIZE;
        object = new Ellipse2D.Double(posX, posY, width, height);
        center = new Ellipse2D.Double(posX + width/4, posY + height/4, width/2, height/2);
        setSize(40, 40);
    }

    public void setSize(int w, int h) {
        height=h;
        width=w;
        object.width=height;
        object.height=width;
        center.width=height/2;
        center.height=width/2;
        center.x=getX()+width/4;
        center.y=getY()+height/4;
    }

    public Shape getShape() {
        return object;
    }
    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(getColor());
        g2d.fill(object);
        g2d.draw(object);

        if (getColor() == Color.BLACK)
            g2d.setColor(Color.DARK_GRAY);
        else
            g2d.setColor(getColor().darker());

        g2d.fill(center);
        g2d.draw(center);
    }

    public int getSize() {
        return width;
    }

}
