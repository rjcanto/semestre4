/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import SameGame.Game.HighScores;
import SameGame.Game.SameGameEngineAbstract;
import SameGame.Game.SameGameEngine_I;
import SameGame.Game.SameGameEngine_I;
import SameGame.Game.model.Block;
import javax.swing.JPanel;

/**
 *
 * @author Nuno
 */
public interface SameGameUI_I {

    public void setGameEngine(SameGameEngineAbstract c);
    public SameGameEngine_I getGameEngine();

    /*View Options*/
    public String[] getLayoutNames();
    public int getActiveLayout();
    public void setActiveLayout(int i);

    public void setGamePanel(GamePanel gamePanel);
    public void setInfoPanel(InfoPanel infoPanel);

    public String[] getBlockShapeNames();
    public int getActiveBlockShape();
    public void setBlockShape(int i);

    public void showHighScores();
    public void showHighScores(HighScores hs);
    public String getHighScoreName();

    public void undoMove();
    public void rotate(boolean right);
    public void clickedBlock(int r, int c);
    public void newGame();
    public void exit();

}
