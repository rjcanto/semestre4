/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import SameGame.Game.SameGameEngine;
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

    public CenterPanel(SameGameUI_I ui){
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BorderLayout());
        setOpaque(false);
        setSize(500,500);
        setName("Center Panel");
        JPanel game =new GamePanel(ui);
        center.add(game);
        add(center);
    }



}
