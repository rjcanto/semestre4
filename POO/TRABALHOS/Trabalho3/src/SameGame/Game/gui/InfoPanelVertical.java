/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui;

import java.awt.Color;
import java.awt.Dimension;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import SameGame.Fonts.Fonts;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.SwingConstants;

/**
 *
 * @author
 */
public class InfoPanelVertical extends InfoPanel implements GameGUIVars_I, SwingConstants{

    public InfoPanelVertical(SameGameUI_I ui){
        super(ui,200,600);
        getGameUI().setInfoPanel(this);
        this.add(initPanel());
    }

    private JPanel initPanel(){
        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new BoxLayout(centerPanel, BoxLayout.Y_AXIS));
        centerPanel.setOpaque(true);
        centerPanel.setSize(200,600);

        /*remaining blocks labels*/
        JLabel rb = new JLabel("Remaining Blocks:");
        rb.setFont(Fonts.INFOFONT_SMALL);
        rb.setForeground(Color.GRAY);

        getRemBlocks().setFont(Fonts.INFOFONT_MEDIUM);
        getRemBlocks().setForeground(Color.red);

        centerPanel.add(rb);
        centerPanel.add(Box.createRigidArea(new Dimension(0,10)));
        centerPanel.add(getRemBlocks());
        centerPanel.add(Box.createRigidArea(new Dimension(0,40)));

        /*parcial score labels*/
        JLabel parcial_score_text = new JLabel("Selection Score:");
        parcial_score_text.setFont(Fonts.INFOFONT_SMALL);
        parcial_score_text.setForeground(Color.GRAY);

        getPScore().setFont(Fonts.INFOFONT_MEDIUM);
        getPScore().setForeground(Color.red);

        centerPanel.add(parcial_score_text);
        centerPanel.add(Box.createRigidArea(new Dimension(0,10)));

        centerPanel.add(getPScore());
        centerPanel.add(Box.createRigidArea(new Dimension(0,40)));

        /*score labels*/
        JLabel score_text = new JLabel("Score:");
        score_text.setFont(Fonts.INFOFONT_MEDIUM);
        score_text.setForeground(Color.GRAY);

        getScore().setFont(Fonts.INFOFONT_LARGE);
        getScore().setForeground(Color.red);

        centerPanel.add(score_text);
        centerPanel.add(Box.createRigidArea(new Dimension(0,10)));
        centerPanel.add(getScore());

        ImageIcon rightButtonIcon = new ImageIcon(ICON_RR_IMAGEPATH);
        ImageIcon leftButtonIcon = new ImageIcon(ICON_RL_IMAGEPATH);

        JLabel rl = new JLabel("Rot. Left:");
        rl.setFont(Fonts.INFOFONT_SMALL);
        rl.setForeground(Color.GRAY);

        getRotateLimit().setFont(Fonts.INFOFONT_MEDIUM);
        getRotateLimit().setForeground(Color.red);

        centerPanel.add(Box.createRigidArea(new Dimension(0,120)));
        centerPanel.add(rl);
        centerPanel.add(Box.createRigidArea(new Dimension(0,5)));
        centerPanel.add(getRotateLimit());
        centerPanel.add(Box.createRigidArea(new Dimension(0,5)));

        getRotateLimit().setFont(Fonts.INFOFONT_MEDIUM);
        getRotateLimit().setForeground(Color.red);

        /*rotate buttons*/
        JButton rotateLeft = new JButton("", leftButtonIcon);
        rotateLeft.setActionCommand("LEFT");
        rotateLeft.setMaximumSize(new Dimension(42, 42));
        rotateLeft.setBackground(Color.lightGray);
        rotateLeft.addActionListener(new rotateButttonAction());
        setRotLeftButton(rotateLeft);
        JButton rotateRight = new JButton("", rightButtonIcon);
        rotateRight.setActionCommand("RIGHT");
        rotateRight.setMaximumSize(new Dimension(42, 42));
        rotateRight.setBackground(Color.lightGray);
        rotateRight.addActionListener(new rotateButttonAction());
        setRotRightButton(rotateRight);

        centerPanel.add(rotateLeft);
        centerPanel.add(Box.createRigidArea(new Dimension(0,5)));
        centerPanel.add(rotateRight);

        centerPanel.add(Box.createRigidArea(new Dimension(0,50)));

        getGameMessage().setFont(Fonts.INFOFONT_SMALL);
        getGameMessage().setForeground(Color.red);
        centerPanel.add(getGameMessage());

        updateInfo();
        return centerPanel;
    }

    private class rotateButttonAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            //System.out.println(e.getActionCommand());
            getGameUI().rotate(e.getActionCommand().equalsIgnoreCase("RIGHT"));
        }
    }
}
