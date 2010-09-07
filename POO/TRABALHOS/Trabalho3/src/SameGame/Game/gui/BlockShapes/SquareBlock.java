/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package SameGame.Game.gui.BlockShapes;

import SameGame.Game.gui.GameBlock;
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

    public SquareBlock(Color c, int posY, int posX) {
        super(c,posX,posY);
        object = new Rectangle2D.Double(getX(), getY(), getWidth()-10, getHeight()-10);
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
        if (this.isSelected()){
            paintSelection(g2d, object);
        }else{
            g2d.draw(object);
        }
        
    }

    public int getSize() {
        return SIZE;
    }

    public Shape getShape() {
        return object;
    }

}
