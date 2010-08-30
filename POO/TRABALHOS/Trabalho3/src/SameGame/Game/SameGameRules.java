package SameGame;

import SameGame.Game.model.Block;

/**
 *
 * @author Nuno
 */
public abstract class SameGameRules implements SameGameRules_I {

    public void newGame() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean selectBlock(int x, int y) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean unselectBlock(int x, int y) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean removeBlock(int x, int y) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public String[] viewHighScores() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean verifyWin() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean verifyStuck() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

   
}
