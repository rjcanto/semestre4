/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.io.File;
import java.io.FilenameFilter;
import java.util.Random;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.BevelBorder;
import javax.swing.border.Border;
import test.Fonts.Fonts;

/**
 *
 * @author nac
 */
public class InfoPanel extends JPanel implements GameGUIVars {
    
    private final File imageDir = new File(INFOIMAGEPATH);
    private String[] image;
    private FilenameFilter filter;
    private ImageIcon bg;
    private JLabel bgl;
    private String filename;
    public InfoPanel(){
        //This Panel
        setLayout(new BorderLayout());
        setOpaque(false);
        setSize(200,600);
        //setLocation(600, 0);
        setName("Info Panel");

        //Set BackGround
        filter = new FilenameFilter() { public boolean accept(File dir, String name) { return !name.startsWith(".") && name.endsWith(".jpg"); } };
        image = imageDir.list(filter);
        filename=INFOIMAGEPATH+(image[(new Random().nextInt(image.length*71))%image.length]);
        bg = new ImageIcon(filename);
        bgl = new JLabel();
        bgl.setIcon(bg);
        bgl.setLocation(0, 0);
     
        Container center = new Container();
        //System.out.print(imageDir.getAbsolutePath()+" -- " + filename);
        center.setLayout(new BorderLayout());
        center.setLocation(0, 0);
        
        

        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new BoxLayout(centerPanel, 1));
        centerPanel.setOpaque(false);
        centerPanel.setBackground(new Color(205, 155, 250, 0));
        centerPanel.setSize(200,600);
                


        JLabel x = new JLabel("Info Panel");
        JButton a = new JButton("Info PanelA");
        JButton b = new JButton("Info PanelB");
        JButton c = new JButton("Info PanelC");
        JButton d = new JButton("Info PanelD");

        x.setFont(Fonts.INFOFONT);
        x.setForeground(Color.red);
        x.setAlignmentX(CENTER_ALIGNMENT);
        a.setAlignmentX(CENTER_ALIGNMENT);
        b.setAlignmentX(CENTER_ALIGNMENT);
        c.setAlignmentX(CENTER_ALIGNMENT);
        d.setAlignmentX(CENTER_ALIGNMENT);

        x.setLocation(50, 75);
        a.setLocation(150, 75);
        b.setLocation(250, 75);
        c.setLocation(350, 75);
        d.setLocation(450, 75);


        centerPanel.add(x);
        centerPanel.add(a);
        centerPanel.add(b);
        centerPanel.add(c);
        centerPanel.add(d);
        
        center.add(centerPanel);
       
        add(center);
        center.add(bgl);
    }
}
