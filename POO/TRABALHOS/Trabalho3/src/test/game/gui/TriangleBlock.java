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

/**
 *
 * @author nac
 */
public class TriangleBlock extends GameBlock {
    private Polygon object;
    private int width;
    private int height;

    private int[] getXpoint(){
        int[] xx={0,width/2,width};
        return xx;
    }
    private int[] getYpoint(){
        int[] yy={height,0,height};
        return yy;
    }
    public TriangleBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        width=height=SIZE;
        int[] xx=getXpoint();
        int[] yy=getYpoint();
        object = new Polygon(xx,yy,xx.length);
        object.translate(posX, posY);
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
    }
    public int getSize() {
        return SIZE;
    }

}
