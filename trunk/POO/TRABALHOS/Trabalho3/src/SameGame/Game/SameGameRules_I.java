package SameGame;

import SameGame.Game.SameGameEngine;
import SameGame.Game.model.Board;

/**
 *
 * @author Nuno
 */
public interface SameGameRules_I {
    public void setGameEngine(SameGameEngine eng);
    public void setBoard(Board b);
    public void selectBlock(int r, int c);
    public void unselectBlock(int r, int c);
    public void updateScore(int score);
    public void updateScore();
    public void setParcialScore(int score);
    public void rotateBoard(boolean right);
    public boolean verifyWin();
    public boolean verifyStuck();
}
