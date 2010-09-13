/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.gui;

import java.awt.BorderLayout;
import java.awt.Container;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.border.Border;


public class CenterPanel extends JPanel {
    public static final Border CENTER_BORDER = BorderFactory.createTitledBorder("XPTO");

    public CenterPanel(SameGameUI_I ui){
        setLayout(new BorderLayout());
        Container center = new Container();
        center.setLayout(new BorderLayout());
        setOpaque(false);
        setSize(500,500);
        setName("Center Panel");
        JPanel game =new GamePanel(ui);
        center.add(game);
        add(center);
    }



}
