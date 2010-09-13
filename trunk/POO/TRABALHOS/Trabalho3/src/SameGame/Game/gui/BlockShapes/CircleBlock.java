/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.gui.BlockShapes;

import SameGame.Game.gui.GameBlock;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;


public class CircleBlock extends GameBlock {
    private Ellipse2D.Double object;

    public CircleBlock(Color c, int posY, int posX) {
        super(c,posX,posY);
        object = new Ellipse2D.Double(getX(), getY(), getWidth()-10, getHeight()-10);
    }

    public void setSize(int w, int h) {
        super.setSize(w,h);
        object.width=w;
        object.height=h;
    }

    public Shape getShape() {
        return object;
    }
    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(getColor());
        g2d.fill(object);
        if (this.isSelected()){
            paintSelection(g2d, object);
        }else{
            g2d.draw(object);
        }
    }

    public int getSize() {
        return getWidth();
    }

}
