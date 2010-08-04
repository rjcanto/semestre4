/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.util.Random;
import javax.swing.JPanel;

/**
 *
 * @author masterzdran
 */
public class GamePanel extends JPanel {
    GameShape[][] board;
    public GamePanel(){
        Color[] c ={Color.BLACK,Color.BLUE,Color.GREEN,Color.MAGENTA,Color.ORANGE,Color.YELLOW, Color.PINK};
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BorderLayout());
        setBackground(new Color(0, 0, 0, 0));
        setOpaque(false);
        setSize(250,650);
        setName("Game Panel");
        board=new GameShape[9][9];
        for (int line =0;line<9;++line){
            for(int col=0;col<9;++col){
                board[line][col]=new RubiBlock(c[(new Random().nextInt(c.length*71))%c.length], 55*line+20, 55*col+20);
            }
        }
        add(center);
    }
    @Override
    public void paint (Graphics g) {
        for (int line =0;line<9;++line){
            for(int col=0;col<9;++col){
                board[line][col].paintShape(g);
            }
        }
        
    }

}
