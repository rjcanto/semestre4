/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.io.File;
import java.io.FilenameFilter;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import test.Fonts.Fonts;

/**
 *
 * @author nac
 */
public class InfoPanelLong extends JPanel {
    private final String INFOIMAGEPATH ="src/test/images/Layouts/Layout2/infoBG/";
    private final File imageDir = new File(INFOIMAGEPATH);
    private String[] image;
    private FilenameFilter filter;
    private ImageIcon bg;
    private JLabel bgl;
    private String filename;
    public InfoPanelLong(){
        //This Panel
        setLayout(new BorderLayout());
        setOpaque(false);
        setSize(800,100);
        setName("Info Panel");

        //Set BackGround
        filter = new FilenameFilter() { public boolean accept(File dir, String name) { return !name.startsWith(".") &&( name.endsWith(".jpg") ||  name.endsWith(".png") ||  name.endsWith(".gif")); } };
        image = imageDir.list(filter);
        filename=INFOIMAGEPATH+(image[(new Random().nextInt(image.length*71))%image.length]);
        bg = new ImageIcon(filename);
        bgl = new JLabel();
        bgl.setIcon(bg);
        bgl.setLocation(0, 0);
     
        JPanel info = new JPanel();

        info.setLayout(new BorderLayout());
        info.setLocation(0, 0);
        
        

        JPanel centerPanel = new JPanel();
        centerPanel.setOpaque(false);
        centerPanel.setSize(800,100);
        
        JLabel x = new JLabel("Info Panel");
        JButton a = new JButton("Info PanelA");
        JButton b = new JButton("Info PanelB");
        JButton c = new JButton("Info PanelC");
        JButton d = new JButton("Info PanelD");
        a.setPreferredSize(new Dimension(100, 50));
        b.setPreferredSize(new Dimension(100, 50));
        c.setPreferredSize(new Dimension(100, 50));
        d.setPreferredSize(new Dimension(100, 50));
        
        x.setFont(Fonts.INFOFONT);
        x.setForeground(Color.red);
        x.setLocation(10, 10);


        centerPanel.add(x);
        centerPanel.add(a);
        centerPanel.add(b);
        centerPanel.add(c);
        centerPanel.add(d);


       info.add(centerPanel);

       add(info);
        
        info.add(bgl);


    }
}
