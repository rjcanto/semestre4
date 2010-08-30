/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.border.Border;

/**
 *
 * @author nac
 */
public class CenterPanel extends JPanel {
    public static final Border CENTER_BORDER = BorderFactory.createTitledBorder("XPTO");
    public CenterPanel(){
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BorderLayout());
        setOpaque(false);
        setSize(600,600);
        setName("Center Panel");
        JPanel game =new GamePanel();
        center.add(game);
        add(center);
    }


}
