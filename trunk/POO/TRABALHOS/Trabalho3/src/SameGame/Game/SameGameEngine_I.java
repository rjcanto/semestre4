package SameGame.Game;

import SameGame.Game.model.Block;

/**
 *
 * @author Nuno
 */
public interface SameGameEngine_I {
    public void clickedBlock(int x, int y);
    public void newGame();
    public void setScores(int score, int parcialScore);
    public int getScore();
    public int getParcialScore();
}
