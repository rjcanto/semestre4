/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui.BlockShapes;

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

    private int[] getXpoint(){
        int[] xx={getWidth()/2,getWidth()/2,0,getWidth()/2, getWidth()/2,getWidth(),getWidth(),getWidth()/2, getWidth()/2, getWidth(),getWidth()/2,getWidth()/2,getWidth()/2,0,0,getWidth()/2};
        return xx;
    }
    private int[] getYpoint(){
        int[] yy={getHeight()/2,0,0,getHeight()/2, getHeight()/2,0,getHeight()/2,getHeight()/2,getHeight()/2,getHeight(),getHeight(),getHeight()/2,getHeight()/2,getHeight(),getHeight()/2,getHeight()/2};
        return yy;
    }
    public StarBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        int[] xx=getXpoint();
        int[] yy=getYpoint();
        object = new Polygon(xx,yy,xx.length);
        center = new Ellipse2D.Double(getX() + getWidth()/4, getY() + getHeight()/4, getWidth()/2, getHeight()/2);
        object.translate(getX(), getY());
        
    }
    public void setSize(int w, int h) {
        super.setSize(w,h);
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
