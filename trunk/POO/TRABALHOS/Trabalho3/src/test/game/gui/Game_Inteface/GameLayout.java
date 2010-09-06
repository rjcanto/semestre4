/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui.Game_Inteface;

import SameGame.Game.model.Block;
import java.util.LinkedList;
import test.game.model.Score;

/**
 *
 * @author masterzdran
 */
public interface GameLayout {

    public void setScore(int score);
    public void setGameMode(int type);
    public void setLastBonus(int score);
    public void setGameBlock(Block block);
    public void setHighScoreList(LinkedList<Score> highScoreList);

}
