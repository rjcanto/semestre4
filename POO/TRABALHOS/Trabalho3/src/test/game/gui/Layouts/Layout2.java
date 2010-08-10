/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui.Layouts;

import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JPanel;
import test.game.gui.CenterPanel;
import test.game.gui.InfoPanelLong;
import test.game.gui.framePanel;

/**
 *
 * @author Nuno Alexandre Cancelo<nuno.cancelo at gmail.com>
 */
public class Layout2 extends JPanel{
        private JPanel center;
        private JPanel info;
        private JPanel framePanel;

        public Layout2(){
            Container frame = new Container();
            frame.setLayout(new BorderLayout());

            center           = new CenterPanel();
            info             = new InfoPanelLong();
            framePanel        = new framePanel();

            framePanel.setLocation(0,0);
            center.setLocation(150, 0);
            info.setLocation(0,500);

            frame.add(center);
            frame.add(info);
            frame.add(framePanel);
            add(frame);
        }
}
