/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

public class DrawingTest extends Frame {
  Shape circle = new Ellipse2D.Float(100.0f, 100.0f, 100.0f, 100.0f);
  float dash[] = {20};
  Stroke strokedCircle = new BasicStroke(5, BasicStroke.CAP_BUTT, BasicStroke.JOIN_ROUND, 5, dash, 0);


  public void paint(Graphics g) {
    Graphics2D ga = (Graphics2D)g;

    ga.setPaint(Color.red);
    ga.fill(circle);
    ga.setStroke(strokedCircle);
    ga.setPaint(ga.getColor().darker());
    ga.draw(circle);

    
    }

  public static void main(String args[]) {
    Frame frame = new DrawingTest();
    frame.addWindowListener(new WindowAdapter(){
      public void windowClosing(WindowEvent we){
        System.exit(0);
      }
    });
    frame.setSize(300, 250);
    frame.setVisible(true);
  }
}
