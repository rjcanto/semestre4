/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui.Layouts;

import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JPanel;
import test.game.gui.CenterPanel;
import test.game.gui.InfoPanel;
import test.game.gui.framePanel;

/**
 *
 * @author Nuno Alexandre Cancelo<nuno.cancelo at gmail.com>
 */
public class Layout1 extends JPanel{
        private JPanel center;
        private JPanel info;
        private JPanel framePanel;

        public Layout1(){
            Container frame = new Container();
            frame.setLayout(new BorderLayout());

            center           = new CenterPanel();
            info             = new InfoPanel();
            framePanel        = new framePanel();

            framePanel.setLocation(0,0);
            center.setLocation(0, 0);
            info.setLocation(600,0);

            frame.add(center);
            frame.add(info);
            frame.add(framePanel);
            add(frame);
        }
}
