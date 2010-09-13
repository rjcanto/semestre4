/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game;

import SameGame.Game.model.HighScores;
import SameGame.Game.model.Board;
import SameGame.Game.gui.SameGameUI_I;
import SameGame.Game.model.Block;

public interface SameGameEngine_I {

    public void setBoard(Board myBoard);
    public Board getBoard();
    public void setUI(SameGameUI_I myUI);
    public SameGameUI_I getUI();
    public void setGameRules(SameGameRules gameRules);
    public SameGameRules getGameRules();
    public int getHeight();
    public int getWidth();

    public void setGameNames(String[] gameNames);
    public String[] getGameNames();
    public int getGameType();

    public Block getBlock(int r, int c);
    public void clickedBlock(int x, int y);
    public int getRemainingBlocks();
    public void rotateBoard(boolean right);
   
    public int getScore();
    public void updateScore();
    public void resetScores();

    public void initAllHighScores();
    public void clearAllHighScores();
    public HighScores getHighScores();
    public boolean isHighScore();
    public void addHighScore(String name);
    
    public void newGame(boolean continueGame);
    public void undoMove();
    public boolean verifyEnd();
    public boolean verifyStuck();
    public boolean verifyWin();
}
