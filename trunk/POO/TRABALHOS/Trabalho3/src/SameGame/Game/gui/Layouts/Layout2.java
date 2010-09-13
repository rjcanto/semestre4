/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui.Layouts;

import SameGame.Game.gui.CenterPanel;
import SameGame.Game.gui.InfoPanel;
import SameGame.Game.gui.InfoPanelHorizontal;
import SameGame.Game.gui.Layout_I;
import SameGame.Game.gui.framePanel;
import SameGame.Game.gui.SameGameUI_I;
import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JPanel;


public class Layout2 extends JPanel implements Layout_I{
        private CenterPanel center;
        private InfoPanel   info;
        private framePanel  framePanel;

        public Layout2(SameGameUI_I ui){
            Container frame = new Container();
            frame.setLayout(new BorderLayout());

            center           = new CenterPanel(ui);
            info             = new InfoPanelHorizontal(ui);
            framePanel        = new framePanel();

            framePanel.setLocation(0,0);
            center.setLocation(150, 0);
            info.setLocation(0,550);

            frame.add(center);
            frame.add(info);
            frame.add(framePanel);
            add(frame);
        }
        public void changeBG(){
            framePanel.changeBG();
        }
}
