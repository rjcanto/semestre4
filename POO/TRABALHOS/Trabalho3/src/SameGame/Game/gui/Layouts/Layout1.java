/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui.Layouts;

import SameGame.Game.gui.CenterPanel;
import SameGame.Game.gui.InfoPanelVertical;
import SameGame.Game.gui.framePanel;
import SameGame.Game.gui.SameGameUI_I;
import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JPanel;


/**
 *
 * @author Nuno Alexandre Cancelo<nuno.cancelo at gmail.com>
 */
public class Layout1 extends JPanel{
        private JPanel center;
        private JPanel info;
        private JPanel framePanel;

        public Layout1(SameGameUI_I ui){
            Container frame = new Container();
            frame.setLayout(new BorderLayout());

            center           = new CenterPanel(ui);
            info             = new InfoPanelVertical(ui);
            framePanel       = new framePanel(ui);

            framePanel.setLocation(0,0);
            center.setLocation(0, 0);
            info.setLocation(600,0);

            frame.add(center);
            frame.add(info);
            frame.add(framePanel);
            add(frame);
        }
}
