/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author nac
 */
public class framePanel extends JPanel {
    private final String imagepath ="src/test/images/";
    private File imageDir = new File(imagepath);
    private String[] image;
    private ImageIcon bg;
    private JLabel bgl;
    private FilenameFilter filter;
    private String filename;

    public framePanel(){
        filter = new FilenameFilter() { public boolean accept(File dir, String name) { return !name.startsWith(".") && name.endsWith(".jpg"); } };
        image = imageDir.list(filter);
        filename=imagepath+(image[(new Random().nextInt(image.length*71))%image.length]);
        bg = new ImageIcon(filename);
        bgl = new JLabel();
        bgl.setIcon(bg);
        add(bgl);
        setName("Frame Panel");
    }
}
