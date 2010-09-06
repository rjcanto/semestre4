/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui.Layouts;

import SameGame.Game.SameGameEngine;
import SameGame.Game.gui.CenterPanel;
import SameGame.Game.gui.InfoPanel;
import SameGame.Game.gui.InfoPanelHorizontal;
import SameGame.Game.gui.framePanel;
import SameGame.Game.gui.SameGameUI_I;
import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JPanel;


/**
 *
 * @author Nuno Alexandre Cancelo<nuno.cancelo at gmail.com>
 */
public class Layout2 extends JPanel{
        private CenterPanel center;
        private InfoPanel   info;
        private framePanel  framePanel;

        public Layout2(SameGameUI_I ui){
            Container frame = new Container();
            frame.setLayout(new BorderLayout());

            center           = new CenterPanel(ui);
            info             = new InfoPanelHorizontal(ui);
            framePanel        = new framePanel(ui);

            framePanel.setLocation(0,0);
            center.setLocation(150, 0);
            info.setLocation(0,550);

            frame.add(center);
            frame.add(info);
            frame.add(framePanel);
            add(frame);
        }
}
