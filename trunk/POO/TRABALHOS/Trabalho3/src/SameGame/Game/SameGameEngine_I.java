package SameGame.Game;

import SameGame.Game.model.Board;
import SameGame.Game.gui.SameGameUI_I;
import SameGame.Game.model.Block;
import java.util.Observable;

/**
 *
 * @author Nuno
 */
public interface SameGameEngine_I {
    public void setBoard(Board myBoard);
    public Board getBoard();
    public void setUI(SameGameUI_I myUI);
    public SameGameUI_I getUI();
    public int getHeight();
    public int getWidth();

    /*Game Options Operations*/
    public int[] getBlockLimits();
    public void setBlockLimits(int[] limits);
    public String[] getBlockNames();
    public void setBlockNames(String[] names);
    public int getActiveGameType();
    public String[] getGameTypes();
    public void setGameType(int gameID);

    /*Manage Game Score*/
    public int getParcialScore();
    public int getScore();
    public void setParcialScore(int s);
    public void setScores(int s1, int s2);
    public void resetScores();
    public void updateScore();

    /*HighScores operations*/
    public HighScores[] getHighScores();
    public void setHighScores(HighScores[] highScores);
    public void clearAllHighScores();
    public void clearHighScore(int i);
    public boolean saveHighScores();
    public void initAllHighScores();

    /*File operations*/
    public boolean saveAll();
    public boolean saveGame();

    /*Game Operations*/
    public void clickedBlock(int x, int y);
    public void initEngine();
    public void newGame(boolean continueGame);
    public void rotateBoard(boolean right);
    public void undoMove();
    public Block getBlock(int r, int c);
    public void verifyEnd();


    /* opções gráficas*/
    public String getLayoutName();
    public void setLayoutName(String name);
    public String getBlockShapeName();
    public void setBlockShapeName(String name);

    public void exit();
    public int getRemainingBlocks();

}
