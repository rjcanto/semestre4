/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Toolkit;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author nac
 */
public class PausePanel extends JPanel{
    private final int width  = 200;
    private final int height = 100;
    private boolean  ispaused=false;
    private JLabel pause;
    private Color shown=new Color(0, 0, 0, 0);
    private Color notshown=new Color(125, 125, 125, 125);
    public PausePanel(){
        ispaused = false;
        Dimension screenSize    = Toolkit.getDefaultToolkit().getScreenSize();
        setLayout(new BorderLayout());
        setOpaque(true);
        setSize(width,height);
        setName("Game Panel");
        setBackground(shown);
        setLocation((screenSize.width - width)/2, (screenSize.height - height)/2);
        setFocusable(true);
        Container center = new Container();
        center.setLayout(new BorderLayout());
        pause = new JLabel("Game is Paused!");
        
        add(center);
        center.add(pause);
    }
   public void paintShape(Graphics g) {
        setBackground(shown);

    }
}
