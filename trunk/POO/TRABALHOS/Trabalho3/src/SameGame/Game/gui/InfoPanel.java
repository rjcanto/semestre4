/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui;

import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.SwingConstants;

public abstract class InfoPanel extends JPanel implements GameGUIVars_I, SwingConstants{
    private SameGameUI_I myUI;

    private JLabel remBlocks;
    private JLabel pscore;
    private JLabel score;
    private JLabel gameMessage;
    private JLabel rotateLimit;

    private JButton rright;
    private JButton rleft;

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
        gameMessage = new JLabel();
        rotateLimit = new JLabel();
    }

    public SameGameUI_I getGameUI(){return myUI;}
    public JLabel getRemBlocks(){return remBlocks;}
    public void setRemBlocks(JLabel jl){remBlocks=jl;}
    public JLabel getPScore(){return pscore;}
    public void setPScore(JLabel jl){pscore=jl;}
    public JLabel getScore(){return score;}
    public void setScore(JLabel jl){score=jl;}
    public JLabel getGameMessage(){return gameMessage;}
    public void setGameMessage(JLabel jl){gameMessage=jl;}
    public JLabel getRotateLimit(){return rotateLimit;}
    public void setRotateLimit(JLabel jl){rotateLimit=jl;}
    public void setRotRightButton(JButton rr){rright=rr;}
    public void setRotLeftButton(JButton rl){rleft=rl;}

    public void updateInfo() {
        updateLabel(remBlocks, ""+myUI.getGameEngine().getRemainingBlocks());
        updateLabel(pscore, ""+myUI.getGameEngine().getParcialScore());
        updateLabel(score, ""+myUI.getGameEngine().getScore());
        updateLabel(rotateLimit, ""+myUI.getGameEngine().getRotateLimit());
        updateLabel(gameMessage, (myUI.getGameEngine().isGameFinished())?
            "Game Over!":"");
        if (myUI.getGameEngine().canRotate()){
            enableRotateButtons();
        }else{
            disableRotateButtons();
        }
    }

    private void disableRotateButtons(){
        rright.setEnabled(false);
        rleft.setEnabled(false);
    }
    private void enableRotateButtons(){
        rright.setEnabled(true);
        rleft.setEnabled(true);
    }
    public void updateLabel(JLabel label, String text){label.setText(text);}
}
