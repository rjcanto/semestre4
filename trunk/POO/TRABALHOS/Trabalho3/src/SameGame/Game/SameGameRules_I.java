package SameGame;

import SameGame.Game.model.Block;

/**
 *
 * @author Nuno
 */
public interface SameGameRules_I {
    public void newGame();
    public boolean selectBlock(int x, int y);
    public boolean unselectBlock(int x, int y);
    public boolean removeBlock(int x, int y);
    public String[] viewHighScores();
    public boolean verifyWin();
    public boolean verifyStuck();
}
