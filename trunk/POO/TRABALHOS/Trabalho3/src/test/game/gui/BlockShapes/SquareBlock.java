/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui.BlockShapes;

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
    public SquareBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        object = new Rectangle2D.Double(posX, posY, getWidth(), getHeight());
    }
    public void setSize(int w, int h) {
        super.setSize(w,h);
        object.height=h;
        object.width=w;
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
