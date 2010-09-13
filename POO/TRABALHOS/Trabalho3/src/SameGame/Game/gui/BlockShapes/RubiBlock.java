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
import java.awt.geom.Ellipse2D;

public class RubiBlock extends GameBlock {
    private Polygon object;
    private Ellipse2D.Double center;
    private int[] getXpoint(){
        int[] xx={3,getWidth()/2,getWidth()-3,getWidth()/2};
        return xx;
    }
    private int[] getYpoint(){
        int[] yy={getHeight()/2,3,getHeight()/2,getHeight()-3};
        return yy;
    }

    public RubiBlock(Color c, int posY, int posX) {
        super(c,posX,posY);
        int[] xx=getXpoint();
        int[] yy=getYpoint();
        object = new Polygon(xx,yy,xx.length);
        center = new Ellipse2D.Double(getX()+ getWidth()/4 + 3, getY() + getHeight()/4 +3 , getWidth()/2-6, getHeight()/2-6);
        object.translate(getX(), getY());
    }
    public Shape getShape() {
        return object;
    }
    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(getColor());
        g2d.fill(object);
        if (this.isSelected()){
            paintSelection(g2d, object.getBounds());
        }else{
            g2d.draw(object);
        }
        if (getColor() == Color.BLACK)
            g2d.setColor(Color.DARK_GRAY);
        else
            g2d.setColor(getColor().darker());
        g2d.fill(center);
        g2d.draw(center);
    }
    public void setSize(int w, int h) {
        super.setSize(w,h);
        object.xpoints=getXpoint();
        object.ypoints=getYpoint();
        center.width=getHeight()/2;
        center.height=getWidth()/2;
        center.x=getX()+getWidth()/4;
        center.y=getY()+getHeight()/4;
        object.translate(getX(), getY());
    }
    public int getSize() {
        return SIZE;
    }

}
