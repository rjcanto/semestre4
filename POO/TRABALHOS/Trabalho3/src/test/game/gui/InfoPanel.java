/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author nac
 */
public class InfoPanel extends JPanel {
    public InfoPanel(){
        Container center = new Container();
        center.setLayout(new BoxLayout(center, 1));
        setBackground(new Color(55, 25, 255, 100));
        setOpaque(true);
        setSize(250,650);
        setName("Game Panel");
        JLabel l1 =new JLabel("------------");
        center.add(l1);
    }
}
