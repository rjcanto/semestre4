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
 * @author masterzdran
 */
public class GamePanel extends JPanel {

    public GamePanel(){
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BoxLayout(center, 1));
        setBackground(new Color(128, 128, 128, 125));
        setOpaque(true);
        setSize(250,650);
        setName("Info Panel");
        JLabel l1 =new JLabel("------------");
        JLabel l2 =new JLabel("------------");
        JLabel l3 =new JLabel("------------");
        JLabel l4 =new JLabel("------------");

        center.add(l1);
        center.add(l2);
        center.add(l3);
        center.add(l4);
        add(center);

    }

}
