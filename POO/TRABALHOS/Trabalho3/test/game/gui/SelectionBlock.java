/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Polygon;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.Stroke;
import java.awt.geom.PathIterator;
import java.awt.geom.Rectangle2D;
import javax.swing.SwingUtilities;

/**
 *
 * @author nac
 */
public class SelectionBlock {
    private Rectangle rectangle;
    private Polygon object;
    private Color color;
    private Stroke stroke;

    public SelectionBlock() {
        color = Color.DARK_GRAY;
        stroke = new BasicStroke(10);
        object = new Polygon();
        rectangle = new Rectangle();
    }

    public void paintShape(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.setColor(color);
        if (object.npoints>=0){
            g2d.setStroke(stroke);
            g2d.draw(object);
        }
    }

    public void add(Shape s) {
        Rectangle r = s.getBounds();
        if (rectangle.isEmpty())
            rectangle=r;
        else
            SwingUtilities.computeUnion((int)(r.getX()),(int)(r.getY()),
                (int)(r.getWidth()), (int)(r.getHeight()), rectangle);
        
        /*
        object.addPoint((int) (r.getMinX()),(int)(r.getMinY()));
        object.addPoint((int) (r.getMaxX()),(int)(r.getMinY()));
        object.addPoint((int) (r.getMaxX()),(int)(r.getMaxY()));
        object.addPoint((int) (r.getMinX()),(int)(r.getMaxY()));
         */
    }

    public Shape getShape() {
        return object;
    }

}
