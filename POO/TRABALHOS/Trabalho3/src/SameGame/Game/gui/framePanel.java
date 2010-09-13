/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui;

import java.awt.BorderLayout;
import java.io.File;
import java.io.FilenameFilter;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class framePanel extends JPanel implements GameGUIVars_I{
    private File imageDir = new File(FRAMEBG_IMAGEPATH);
    private String[] image;
    private FilenameFilter filter;

    private ImageIcon bg;
    private JLabel bgl;
    private String filename;

    public framePanel(){
        
        setLayout(new BorderLayout());
        filter = new FilenameFilter() { public boolean accept(File dir, String name) { return !name.startsWith(".") && name.endsWith(".jpg"); } };
        image = imageDir.list(filter);
        filename=FRAMEBG_IMAGEPATH+(image[(new Random().nextInt(image.length*71))%image.length]);
        bg = new ImageIcon(filename);
        bgl = new JLabel();
        bgl.setIcon(bg);
        add(bgl);
        setName("Frame Panel");
    }
    public void changeBG(){
        image = imageDir.list(filter);
        filename=FRAMEBG_IMAGEPATH+(image[(new Random().nextInt(image.length*71))%image.length]);
        bg = new ImageIcon(filename);
        bgl = new JLabel();
        bgl.setIcon(bg);
        repaint();
    }
}
