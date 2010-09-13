/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game;

public abstract class SameGameRules implements SameGameRules_I {

    private SameGameEngine myEngine;
    private boolean continuous;

    public SameGameRules(SameGameEngine eng, boolean continuous){
        myEngine = eng;
        this.continuous= continuous;
    }
    public void setGameEngine(SameGameEngine eng){myEngine=eng;}
    public SameGameEngine getGameEngine(){return myEngine;}
    public boolean isContinuous(){return continuous;}
    public abstract void clickedBlock(int r, int c);
    public abstract void rotateBoard(boolean right);
    
    public void setParcialScore(int numBlocks) {
        myEngine.setParcialScore((int) (Math.pow((numBlocks==0)?0:numBlocks-1, 2)));
    }
    public void updateScore(int numBlocks) {
        myEngine.setParcialScore(numBlocks);
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
