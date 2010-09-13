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
import java.awt.Polygon;
import java.awt.Shape;

public class TriangleBlock extends GameBlock {
    private Polygon object;

    private int[] getXpoint(){
        int[] xx={0+5,getWidth()/2,getWidth()-5};
        return xx;
    }
    private int[] getYpoint(){
        int[] yy={getHeight()-5,0+5,getHeight()-5};
        return yy;
    }
    public TriangleBlock(Color c, int posY, int posX) {
        super(c,posX,posY);
        int[] xx=getXpoint();
        int[] yy=getYpoint();
        object = new Polygon(xx,yy,xx.length);
        object.translate(posX, posY);
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
        if (this.isSelected()){
            paintSelection(g2d, object);
        }else{
            g2d.draw(object);
        }
        
    }
    public int getSize() {
        return SIZE;
    }

}
