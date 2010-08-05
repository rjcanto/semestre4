/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;

/**
 *
 * @author nac
 */
public class StarBlock extends GameBlock {
    private Polygon object;
    private Ellipse2D.Double center;
    private int width;
    private int height;

    private int[] getXpoint(){
        int[] xx={width/2,width/2,0,width/2, width/2,width,width,width/2, width/2, width,width/2,width/2,width/2,0,0,width/2};
        return xx;
    }
    private int[] getYpoint(){
        int[] yy={height/2,0,0,height/2, height/2,0,height/2,height/2,height/2,height,height,height/2,height/2,height,height/2,height/2};
        return yy;
    }
    public StarBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        width=height=SIZE;
        int[] xx=getXpoint();
        int[] yy=getYpoint();
        object = new Polygon(xx,yy,xx.length);
        center = new Ellipse2D.Double(posX + width/4, posY + height/4, width/2, height/2);
        object.translate(getX(), getY());
    }
    public void setSize(int w, int h) {
        height=h;
        width=w;
        object.xpoints=getXpoint();
        object.ypoints=getYpoint();
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
        return SIZE;
    }

}
