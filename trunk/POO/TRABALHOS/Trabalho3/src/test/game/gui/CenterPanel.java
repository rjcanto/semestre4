/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import javax.swing.BoxLayout;
import javax.swing.JPanel;

/**
 *
 * @author nac
 */
public class CenterPanel extends JPanel {
    public CenterPanel(){
        Container center = new Container();
        center.setLayout(new BorderLayout());
        add(center);
        setBackground(new Color(255, 255, 255, 100));
        setOpaque(true);
        setSize(600,650);
        setName("Info Panel");
    }
}
