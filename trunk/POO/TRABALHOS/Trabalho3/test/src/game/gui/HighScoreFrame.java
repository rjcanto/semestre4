/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Timer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author Nuno Alexandre Cancelo<nuno.cancelo at gmail.com>
 */
public class HighScoreFrame extends JPanel implements MouseListener {

    private boolean _isshow;
    private int _xx;
    private int _yy;
    private Graphics2D _string;
    private Thread _t;

    public HighScoreFrame() {
        _isshow = true;
        _xx = 0;
        _yy = 10;
        _t = new Thread("HighScoreFrame");

        setSize(new Dimension(100, 500));
        setLayout(new BorderLayout());
        setOpaque(false);

        JLabel high = new JLabel("HighScore");
        high.setBounds(0, 0, 10, 10);
        high.setForeground(Color.BLUE);
        high.setOpaque(false);
        setFocusable(true);
        add(high);
        addMouseListener(this);
        repaint();
    }

   @Override

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.red);
        g.fillRect(_xx, _yy,100,30);
        g.setColor(Color.BLUE);
        g.drawString("HighScore", _xx+25, _yy+20);
        validate();
        repaint();
    }
    private void moveup(Graphics g) {
        for (; _yy - 10 > 10; _yy -= 10) {
                paintComponent(g);
            try {
                _t.sleep(10);
                 g.clearRect(_xx, _yy,100,30);
            } catch (InterruptedException ex) {
                Logger.getLogger(HighScoreFrame.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void movedown(Graphics g) {
        for (; _yy + 10 < 470; _yy += 10) {
            
            try {
                paintComponent(g);
                _t.sleep(10);
                
               
            } catch (InterruptedException ex) {
                Logger.getLogger(HighScoreFrame.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }

    public void mouseClicked(MouseEvent e) {
        if (_isshow) {
            _isshow = false;
            movedown(getGraphics());
        } else {
            _isshow = true;
            moveup(getGraphics());
        }
        System.out.format("xx[%d] yy[%d]\n", _xx, _yy);
    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }
}
