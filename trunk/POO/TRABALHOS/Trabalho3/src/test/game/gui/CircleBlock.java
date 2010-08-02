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
public class CircleBlock implements GameShape {
    private Ellipse2D.Double object;
    private Color color;
    private int x;
    private int y;


    public CircleBlock(Color c, int posX, int posY) {
        x = posX;
        y = posY;
        color = c;
        object = new Ellipse2D.Double(posX, posY, SIZE, SIZE);
    }

    public void setPosition(int x, int y) {
        this.x = x;
        this.y = y;
        
    }

    public void setSize(int w, int h) {
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
    public void paintComponent(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.translate(x, y);
        g2d.setColor(color);
        g2d.fill(object);
        g2d.draw(object);
    }

    public int getSize() {
        return SIZE;
    }
}
