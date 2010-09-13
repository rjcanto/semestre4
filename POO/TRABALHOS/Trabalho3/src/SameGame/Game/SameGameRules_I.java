/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game;

public interface SameGameRules_I {
    public void setGameEngine(SameGameEngine eng);
    public void clickedBlock(int r, int c);
    public void updateScore(int score);
    public void updateScore();
    public void setParcialScore(int score);
    public void rotateBoard(boolean right);
    public boolean verifyWin();
    public boolean verifyStuck();
}
