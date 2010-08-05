/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import test.game.gui.Game_Inteface.GameShape_I;
import test.game.gui.BlockShapes.RubiBlock;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Random;
import javax.swing.JPanel;
import javax.swing.event.MouseInputListener;
import sun.java2d.Disposer;

/**
 *
 * @author masterzdran
 */
public class GamePanel extends JPanel implements MouseInputListener {
    private GameShape_I[][] board;
    private int BOARD_H = 10;
    private int BOARD_W = 10;
    private Color[] colo ={Color.BLACK,Color.BLUE,Color.GREEN,Color.MAGENTA,Color.ORANGE,Color.YELLOW, Color.PINK};
    public GamePanel(){
        Color[] c ={Color.BLACK,Color.BLUE,Color.GREEN,Color.MAGENTA,Color.ORANGE,Color.YELLOW, Color.PINK};
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BorderLayout());
        setBackground(new Color(0, 0, 0, 0));
        setOpaque(true);
        setSize(250,650);
        setName("Game Panel");
        board=new GameShape_I[BOARD_H][BOARD_W];
        for (int line =0;line<BOARD_H;++line){
            for(int col=0;col<BOARD_W;++col){
                board[line][col]=new RubiBlock(c[(new Random().nextInt(c.length*71))%c.length], 55*line+20, 55*col+20);
            }
        }
        add(center);
        addMouseListener(this);
    }
    @Override
    public void paint (Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D)g;
        for (int line =0;line<BOARD_H;++line){
            for(int col=0;col<BOARD_W;++col){
                
                    board[line][col].paintShape(g2);

            }
        }
        
    }

    public void mouseClicked(MouseEvent e) {
        if(e.getX() > 20 && e.getY()> 20 && e.getX() < 565 && e.getY()<565  ){
            int line = (e.getX()/60);
            int col = (e.getY()/60);
            System.out.print("--> "+e.getX()+" <-- --> "+e.getY()+" <--");
            System.out.print("--> ["+line+"] <-- --> ["+col+"] <--\n");
            //board[line][col].setColor(colo[(new Random().nextInt(colo.length*71))%colo.length]);
            //board[line][col] = null;
            
            
        }

    }

    public void mousePressed(MouseEvent e) {

    }

    public void mouseReleased(MouseEvent e) {

    }

    public void mouseEntered(MouseEvent e) {

    }

    public void mouseExited(MouseEvent e) {

    }

    public void mouseDragged(MouseEvent e) {

    }

    public void mouseMoved(MouseEvent e) {

    }

}
