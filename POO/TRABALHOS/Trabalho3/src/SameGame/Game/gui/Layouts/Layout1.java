/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui.Layouts;

import SameGame.Game.gui.Layout_I;
import SameGame.Game.gui.CenterPanel;
import SameGame.Game.gui.InfoPanel;
import SameGame.Game.gui.InfoPanelVertical;
import SameGame.Game.gui.framePanel;
import SameGame.Game.gui.SameGameUI_I;
import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.JPanel;


public class Layout1 extends JPanel implements Layout_I{
        private CenterPanel center;
        private InfoPanel info;
        private framePanel framePanel;

        public Layout1(SameGameUI_I ui){
            Container frame = new Container();
            frame.setLayout(new BorderLayout());

            center           = new CenterPanel(ui);
            info             = new InfoPanelVertical(ui);
            framePanel       = new framePanel();

            framePanel.setLocation(0,0);
            center.setLocation(0, 0);
            info.setLocation(600,0);

            frame.add(center);
            frame.add(info);
            frame.add(framePanel);
            add(frame);
        }

        public void changeBG(){
            framePanel.changeBG();
        }
}
