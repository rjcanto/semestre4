/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui.Game_Interfaces;

import SameGame.Game.model.HighScores;
import SameGame.Game.model.Block;
import java.util.LinkedList;


public interface GameLayout_I {

    public void setScore(int score);
    public void setGameMode(int type);
    public void setLastBonusPoints(int score);
    public void setGameBlock(Block block);
    public void setHighScoreList(LinkedList<HighScores> highScoreList);

}
