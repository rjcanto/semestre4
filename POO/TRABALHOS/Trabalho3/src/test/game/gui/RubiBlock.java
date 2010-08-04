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
public class RubiBlock implements GameShape {
    
    private Polygon object;
    private Color color;
    private int x;
    private int y;
    private Ellipse2D.Double center;
    public RubiBlock(Color c, int posX, int posY) {
        x = posX;
        y = posY;

        color = c;
        int[] xx={0,SIZE/2,SIZE,SIZE/2};
        int[] yy={SIZE/2,0,SIZE/2,SIZE};
        object = new Polygon(xx,yy,xx.length);
        center = new Ellipse2D.Double(posX + SIZE/4, posY + SIZE/4, SIZE/2, SIZE/2);
        object.translate(x, y);
    }

    public void setPosition(int x, int y) {
        this.x = x;
        this.y = y;
        object.translate(x, y);
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }
    public void setX(int x){
        this.x = x;
    }
    public void setY(int y){
        this.y=y;
    }
    public void setColor(Color color) {
        this.color = color;
    }
    public Color getColor(){
        return color;
    }
    public Shape getShape() {
        return object;
    }


    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(color);
        g2d.fill(object);
        g2d.draw(object);
        if (color == Color.BLACK)
            g2d.setColor(Color.LIGHT_GRAY);
        else
            g2d.setColor(Color.DARK_GRAY);
        g2d.fill(center);
        g2d.draw(center);
    }
    public int getSize() {
        return SIZE;
    }

}
