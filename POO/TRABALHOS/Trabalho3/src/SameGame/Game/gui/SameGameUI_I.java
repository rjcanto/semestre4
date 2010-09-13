/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui;

import SameGame.Game.model.HighScores;
import SameGame.Game.SameGameEngineAbstract;


public interface SameGameUI_I {

    public void setGameEngine(SameGameEngineAbstract c);
    public SameGameEngineAbstract getGameEngine();

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
