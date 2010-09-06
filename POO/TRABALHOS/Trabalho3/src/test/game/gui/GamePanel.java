/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import test.game.gui.Game_Interfaces.GameShape_I;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Rectangle;
import java.awt.event.MouseEvent;
import java.util.Random;
import javax.swing.JPanel;
import javax.swing.event.MouseInputListener;
import test.game.gui.BlockShapes.*;

/**
 *
 * @author masterzdran
 */
public class GamePanel extends JPanel implements MouseInputListener {
    private GameShape_I[][] board;
    
    private SelectionBlock selected = new SelectionBlock();

    private int BOARD_H = 10;
    private int BOARD_W = 10;
    private int width;
    private int height;
    private Color[] c ={Color.BLACK,Color.BLUE,Color.GREEN,Color.MAGENTA,Color.ORANGE,Color.YELLOW, Color.PINK};
    public GamePanel(){
        setLayout(new GridLayout(BOARD_H,BOARD_W));
        setOpaque(false);
        setName("Game Panel");
        board=new GameShape_I[BOARD_H][BOARD_W];
        for (int line =0;line<BOARD_H;++line){
            for(int col=0;col<BOARD_W;++col){
                board[line][col]=new SquareBlock(c[(new Random().nextInt(c.length*71))%c.length], line, col);
            }
        }
        width = board[0][0].getWidth();
        height = board[0][0].getHeight();
        addMouseListener(this);
    }
    @Override
    public void paint (Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D)g;
        Graphics2D selection = (Graphics2D)g;
        for (int line =0;line<BOARD_H;++line){
            for(int col=0;col<BOARD_W;++col){
                    if( board[line][col] != null){
                        if (board[line][col].isSelected())
                            selected.add((board[line][col].getShape()));
                        board[line][col].paintShape(g2);
                }
            }
        }
        selected.paintShape(selection);
        this.validate();
        this.repaint();
    }

    public void mouseClicked(MouseEvent e) {
        if(e.getX() > 0 && e.getY()> 0 && e.getX() < 500 && e.getY()<500  ){
            System.out.println(e.getX()+":"+e.getY());
            int line = (e.getX()/width);
            int col = (e.getY()/height);
            System.out.println(line+":"+col);
            if (board[line][col]==null) return;
            if (board[line][col].isSelected())
                board[line][col].unselect();
            else
                board[line][col].select();
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
