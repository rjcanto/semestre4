/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui.BlockShapes;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.geom.Rectangle2D;

/**
 *
 * @author nac
 */
public class SquareBlock extends GameBlock {
    private Rectangle2D.Double object;

    public SquareBlock(Color c, int posX, int posY) {
        super(c,posX,posY);
        object = new Rectangle2D.Double(getX(), getY(), getWidth()-10, getHeight()-10);
        //this.setSize(50, 50);
    }
    public void setSize(int w, int h) {
        super.setSize(w,h);
        object.height=h;
        object.width=w;
    }
    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(getColor());
/*        if (this.isSelected()){
            Stroke stroke = new BasicStroke(10);
            g2d.setStroke(stroke);
            g2d.fill(object);
            Color aux = getColor();
            g2d.setColor(Color.RED);
            g2d.draw(object);
            stroke = new BasicStroke(0);
            g2d.setStroke(stroke);
            g2d.setColor(aux);
        }else{*/
        g2d.fill(object);
        g2d.draw(object);
       // }
    }

    public int getSize() {
        return SIZE;
    }

    public Shape getShape() {
        return object;
    }

}
