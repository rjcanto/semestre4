package SameGame.Game;

import SameGame.Game.model.Board;

/**
 *
 * @author Nuno
 */
public abstract class SameGameRules implements SameGameRules_I {

    private SameGameEngine myEngine;

    public SameGameRules(SameGameEngine eng){myEngine = eng;}
    public void setGameEngine(SameGameEngine eng){myEngine=eng;}
    public SameGameEngine getGameEngine(){return myEngine;}
    public abstract void clickedBlock(int r, int c);
    public abstract void rotateBoard(boolean right);
    
    public void setParcialScore(int numBlocks) {
        myEngine.setParcialScore((int) (Math.pow(numBlocks-1, 2)));
    }
    public void updateScore(int numBlocks) {
        myEngine.setParcialScore((int) (Math.pow(numBlocks-1, 2)));
        myEngine.updateScore();
    }
    public void updateScore() {
        myEngine.updateScore();
    }
    public void resetScores(){
        myEngine.resetScores();
    }
    public void addWinBonus(){
        updateScore(100);
    }
    public boolean verifyWin() {
        return (myEngine.getBoard().getRemainingBlocks()==0);
    }
    public boolean verifyStuck() {
        if (verifyWin()) return true;
        return (!myEngine.getBoard().verifySelectable());
    }
}
