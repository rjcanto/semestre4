package SameGame.Game;

import SameGame.Game.model.Board;
import SameGame.SameGameRules_I;

/**
 *
 * @author Nuno
 */
public abstract class SameGameRules implements SameGameRules_I {

    private SameGameEngine myEngine;
    private Board myBoard;

    public SameGameRules(SameGameEngine eng){myEngine = eng;}
    public void setGameEngine(SameGameEngine eng){myEngine=eng;}
    public void setBoard(Board b){myBoard=b;}
    public SameGameEngine getGameEngine(){return myEngine;}
    public abstract void selectBlock(int r, int c);
    public abstract void unselectBlock(int r, int c);
    public abstract void rotateBoard(boolean right);
    
    public void setParcialScore(int score) {
        myEngine.setParcialScore((score-1)^2);
    }
    public void updateScore(int score) {
        myEngine.setParcialScore((score-1)^2);
        myEngine.updateScore();
    }
    public void updateScore() {
        myEngine.updateScore();
    }
    public void resetScores(){
        myEngine.resetScores();
    }
    public boolean verifyWin() {
        return (myEngine.getBoard().getRemainingBlocks()==0);
    }
    public boolean verifyStuck() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
