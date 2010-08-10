/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui.BlockShapes;

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

    public CircleBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        object = new Ellipse2D.Double(getX(), getY(), getWidth(), getHeight());
        center = new Ellipse2D.Double(getX() + getWidth()/4, getY() + getHeight()/4, getWidth()/2, getHeight()/2);
        this.setSize(40, 40);
    }

    public void setSize(int w, int h) {
        super.setSize(w,h);
        object.width=w;
        object.height=h;
        center.width=w/2;
        center.height=h/2;
        center.x=getX()+w/4;
        center.y=getY()+h/4;
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
        return getWidth();
    }

}
