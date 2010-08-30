/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game;

import SameGame.Game.model.Board;
import SameGame.SameGameUI_I;
import java.io.*;

/**
 *
 * @author Nuno
 */
public class SameGameEngine implements SameGameEngine_I, SameGameVars_I {
    private Board myBoard;
    private SameGameUI_I myUI;
    private SameGameRules gameRules;
    private HighScores[] highScores;

    private FileAccess file;
    private String[] gameNames;

    private int gameType;
    private int width;
    private int heigth;
    private int score;
    private int parcialScore;

    public SameGameEngine(int height, int width){
       file = new FileAccess();
       myBoard = new Board(height, width, file.getFileNames(BLOCKS_PACKAGE), false);
       gameNames = file.getFileNames(GAMETYPE_PACKAGE);
       highScores = new HighScores[gameNames.length];
       gameType=0;
       this.width=width;
       this.heigth=height;
       score=parcialScore=0;
    }
    public String[] getGameType() {return gameNames;}
    public SameGameRules getGameRules() {return gameRules;}
    public void setGameRules(SameGameRules gameRules) {this.gameRules = gameRules;}
    public int getHeigth() {return heigth;}
    public void setHeigth(int heigth) {this.heigth = heigth;}
    public int getWidth() {return width;}
    public void setWidth(int width) {this.width = width;}
    public SameGameUI_I getUI() {return myUI;}
    public void setUI(SameGameUI_I myUI) {this.myUI = myUI;}
    public Board getBoard() {return myBoard;}
    public void setBoard(Board myBoard) {this.myBoard = myBoard;}
    public HighScores[] getHighScores() {return highScores;}
    public void setHighScores(HighScores[] highScores) {this.highScores = highScores;}
    @Override
    public String toString(){
        return ""+this.score+FILE_DELIMITERS+this.parcialScore+FILE_DELIMITERS+
                "\n"+this.width+FILE_DELIMITERS+this.heigth+FILE_DELIMITERS;
    }

    /*
     * métodos para actualizar os Scores
     */
    public int getScore(){return score;}
    public int getParcialScore(){return parcialScore;}
    public void setScores(int s1, int s2){score=s1;parcialScore=s2;}
    public void resetScores(){score=0; parcialScore=0;}
    public void updateScore() {score+=parcialScore; parcialScore=0;}
    public void setParcialScore(int s){this.parcialScore=s;}

    public boolean selectBlock(int x, int y) {
        return gameRules.selectBlock(x, y);
    }

    public boolean unselectBlock(int x, int y) {
        return gameRules.unselectBlock(x, y);
    }


    public void newGame() {
        myBoard.init();
    }

    





}
