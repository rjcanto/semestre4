/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author nac
 */
public class framePanel extends JPanel {
    final String imagepath ="src/test/images/";
    final String[] image = {"dataattack.jpg","mech.jpg","monsters.jpg","pacman.jpg","Sea.jpg","time-to-relax.jpg","fafa.jpg","Zon.jpg","B.jpg","whisky.jpg","whisky.jpg","royal.jpg","CC.jpg"};
    ImageIcon bg;
    JLabel bgl;
    public framePanel(){
        this.changeBG();
    }
    public void changeBG(){
        String filename=imagepath+(image[(new Random().nextInt(image.length*71))%image.length]);
        bg = new ImageIcon(filename);
        bgl = new JLabel();
        bgl.setIcon(bg);
        add(bgl);
        setName("Frame Panel");
    }
}
