
package SameGame.Game;

import SameGame.Game.gui.SameGameUI_I;
import SameGame.Game.model.Block;
import SameGame.Game.model.Board;
import java.util.Observable;

public abstract class SameGameEngineAbstract extends Observable implements SameGameEngine_I{
    private Board myBoard;
    private SameGameUI_I myUI;
    private SameGameRules gameRules;

    private FileAccess savedOptions;

    private HighScores[] highScores;
    private FileAccess file;

    private String[] gameNames;
    private int gameID;
    private int newGameID; //usado para começar um novo jogo com regras diferentes

    private String[] blockNames;
    private int[] blockLimit;
    private int[] newBlockLimit; //usado para definir novos limites
                                  //de utilização dos blocos

    private int width;
    private int height;
    private int score;
    private int parcialScore;
    private boolean gameFinished;

    /*constructor*/
    public SameGameEngineAbstract(int height, int width){
        this.height=height;
        this.width=width;
    }

    /*getter and setters for private variables*/
    public int getHeight() {return height;}
    public int getWidth() {return width;}

    public Board getBoard() {return myBoard;}
    public void setBoard(Board myBoard) {this.myBoard = myBoard;}
    public SameGameUI_I getUI() {return myUI;}
    public void setUI(SameGameUI_I myUI) {this.myUI = myUI;}
    public SameGameRules getGameRules() {return gameRules;}
    public void setGameRules(SameGameRules gameRules) {this.gameRules = gameRules;}

    public void setFile(FileAccess f){this.savedOptions=f;}
    public FileAccess getFile(){return savedOptions;}

    public String[] getBlockNames() {return blockNames;}
    public void setBlockNames(String[] names) {
        this.blockNames = new String[names.length];
        System.arraycopy(names, 0, this.blockNames, 0, names.length);
    }
    public String[] getGameNames() {return gameNames;}
    public void setGameNames(String[] gameNames) {
        this.gameNames = new String[gameNames.length];
        System.arraycopy(gameNames, 0, this.gameNames, 0, gameNames.length);
    }

    /*
     * limites dos blocos tem de ter mesmo numero de posicoes que
     * nomes dos blocos. actualiza os nomes para o proximo jogo
     */
    public int[] getBlockLimits() {return blockLimit;}
    public int[] getNewBlockLimits(int[] limits) {return newBlockLimit;}
    public void setNewBlockLimits(int[] limits) {
        newBlockLimit=new int[blockNames.length];
        System.arraycopy(limits, 0, newBlockLimit, 0, limits.length);
    }
    public int[] updateBlockLimits(){
        if (newBlockLimit==null) newBlockLimit = new int[blockNames.length];
        blockLimit = new int[newBlockLimit.length];
        System.arraycopy(newBlockLimit, 0, blockLimit, 0, blockLimit.length);
        return blockLimit;
    }
    public int[] updateBlockLimits(int[] newBL){
        setNewBlockLimits(newBL);
        updateBlockLimits();
        return blockLimit;
    }
    /*
     * actualiza o tipo de jogo e guarda o tipo do próximo.
     */
    public int getGameType() {return gameID;}
    public int getNewGameType() {return newGameID;}
    public void setNewGameType(int gameID) {this.newGameID=gameID;}
    public int updateGameType() {gameID=newGameID;return gameID;}
    public int updateGameType(int gameID) {
        setNewGameType(gameID);
        return updateGameType();
    }
    /*
     * métodos para manipular a pontuação e a pontuação parcial (blocos seleccionados)
     */
    public void setScores(int s1, int s2){score=s1;parcialScore=s2;}
    public int getScore(){return score;}
    public int getParcialScore(){return parcialScore;}
    public void resetScores(){setScores(0,0);}
    public void updateScore() {setScores(score+parcialScore,0);}
    public void setParcialScore(int s){this.parcialScore=s;}

    /*
     * métodos para os HighScores
     */
    public HighScores[] getAllHighScores() {return highScores;}
    public void setHighScores(HighScores[] highScores) {
        this.highScores = new HighScores[highScores.length];
        System.arraycopy(highScores, 0, this.highScores, 0, highScores.length);
    }
    public void initAllHighScores(){
        highScores = new HighScores[gameNames.length];
        for (int i=0; i<highScores.length; ++i)
            highScores[i]= new HighScores();
    }
    public void clearAllHighScores(){
        for (int i=0; i<highScores.length; ++i)
            clearHighScore(i);
    }
    public void clearHighScore(int i){highScores[i].clearHighScores();}
    public boolean isHighScore(){return highScores[gameID].isHighScore(score);}
    public void addHighScore(String name){highScores[gameID].addHighScore(name, score);}
    public HighScores getHighScores(){return highScores[gameID];}

    /*acesso a métodos do board*/
    public int getRemainingBlocks(){return myBoard.getRemainingBlocks();}
    public Block getBlock(int r, int c){return myBoard.getBlock(r, c);}

    /*verifica se o jogo terminou quando faz o load do ficheiro para 
     *que não esteja sempre a pedir para adicionar HighScores
     */
    public boolean isGameFinished(){return gameFinished;}
    public void gameFinished(){gameFinished=true;}
    public void gameStarted(){gameFinished=false;}
    
    public boolean isContinuous(){return gameRules.isContinuous();}
    public abstract boolean verifyEnd();
    public boolean verifyStuck(){return gameRules.verifyStuck();}
    public boolean verifyWin(){return gameRules.verifyWin();}
    public abstract void newGame(boolean continueSaved);
    public void exit(){System.exit(0);}




}
