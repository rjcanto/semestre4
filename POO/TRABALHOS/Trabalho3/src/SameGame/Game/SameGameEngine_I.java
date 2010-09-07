package SameGame.Game;

import SameGame.Game.model.Board;
import SameGame.Game.gui.SameGameUI_I;
import SameGame.Game.model.Block;

/**
 *
 * @author Nuno
 */
public interface SameGameEngine_I {

    void setBoard(Board myBoard);
    Board getBoard();
    void setUI(SameGameUI_I myUI);
    SameGameUI_I getUI();
    void setGameRules(SameGameRules gameRules);
    SameGameRules getGameRules();
    int getHeight();
    int getWidth();

    void setGameNames(String[] gameNames);
    String[] getGameNames();
    int getGameType();

    Block getBlock(int r, int c);
    void clickedBlock(int x, int y);
    int getRemainingBlocks();
    void rotateBoard(boolean right);
   
    int getScore();
    void updateScore();
    void resetScores();

    public void initAllHighScores();
    public void clearAllHighScores();
    HighScores getHighScores();
    boolean isHighScore();
    public void addHighScore(String name);
    
    void newGame(boolean continueGame);
    void undoMove();
    boolean verifyStuck();
    boolean verifyWin();
}
