/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import java.awt.Color;
import java.awt.Dimension;
import java.io.File;
import java.io.FilenameFilter;
import java.util.Observable;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import SameGame.Fonts.Fonts;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Observer;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.SwingConstants;

/**
 *
 * @author nac
 */
public abstract class InfoPanel extends JPanel implements GameGUIVars_I, SwingConstants{
    private SameGameUI_I myUI;

    private JLabel remBlocks;
    private JLabel pscore;
    private JLabel score;

    public InfoPanel(SameGameUI_I ui){
        this(ui,100,100);
    }
    public InfoPanel(SameGameUI_I ui, int width, int height){
        this.myUI=ui;
        setLayout(new BorderLayout());
        setOpaque(false);
        setSize(width,height);
        setName("Info Panel");
        remBlocks = new JLabel();
        pscore = new JLabel();
        score = new JLabel();
    }

    public SameGameUI_I getGameUI(){return myUI;}
    public JLabel getRemBlocks(){return remBlocks;}
    public void setRemBlocks(JLabel jl){remBlocks=jl;}
    public JLabel getPScore(){return pscore;}
    public void setPScore(JLabel jl){pscore=jl;}
    public JLabel getScore(){return score;}
    public void setScore(JLabel jl){score=jl;}

    public void updateLabels() {
        updateLabel(remBlocks, ""+myUI.getGameEngine().getRemainingBlocks());
        updateLabel(pscore, ""+myUI.getGameEngine().getParcialScore());
        updateLabel(score, ""+myUI.getGameEngine().getScore());
    }

    public void updateLabel(JLabel label, String text){label.setText(text);}
}
