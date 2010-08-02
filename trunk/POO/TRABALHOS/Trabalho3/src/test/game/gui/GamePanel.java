/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JPanel;

/**
 *
 * @author masterzdran
 */
public class GamePanel extends JPanel {
    GameShape c1 ;
    GameShape c2;
    GameShape c3;
    PausePanel p;
    public GamePanel(){
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BorderLayout());
        setBackground(new Color(0, 0, 0, 0));
        setOpaque(false);
        setSize(250,650);
        setName("Game Panel");
         p = new PausePanel();
        c1 = new CircleBlock(Color.green, 10, 10);
        c2 = new SquareBlock(Color.blue, 35, 10);
        c3 = new TriangleBlock(Color.red, 60, 10);

        addMouseListener(new MouseAdapter(){@Override
public void mousePressed(MouseEvent e){moveSquare(e.getX(),e.getY());}});
        addMouseMotionListener(new MouseAdapter(){@Override
public void mouseDragged(MouseEvent e){moveSquare(e.getX(),e.getY());}});


        add(center);

    }
    private void moveSquare(int x, int y){

        // Current square state, stored as final variables
        // to avoid repeat invocations of the same methods.
        final int CURR_X = c1.getX();
        final int CURR_Y = c1.getY();
        final int CURR_W = c1.SIZE;
        final int CURR_H = c1.SIZE;
        final int OFFSET = 1;

        if ((CURR_X!=x) || (CURR_Y!=y)) {

            // The square is moving, repaint background
            // over the old square location.
            repaint(CURR_X,CURR_Y,CURR_W+OFFSET,CURR_H+OFFSET);

            // Update coordinates.
            c1.setX(x);
            c1.setY(y);
            setBackground(new Color(0, 0, 0, 0));
            // Repaint the square at the new location.
            repaint(c1.getX(), c1.getY(),c1.SIZE+OFFSET,c1.SIZE+OFFSET);
        }
    }


    @Override
    public void paint (Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        
        c1.paintComponent(g2);
        c2.paintComponent(g2);
        c3.paintComponent(g2);
        p.paintComponent(g2);
    }

}
