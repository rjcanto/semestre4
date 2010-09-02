/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game;

import SameGame.Game.model.Board;
import SameGame.SameGameUI_I;

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
    private int activeGameID;

    private String[] blockNames;
    private String[] activeBlockNames;
    private int[] blockLimit;
    
    private int width;
    private int height;
    private int score;
    private int parcialScore;

    public SameGameEngine(int height, int width){
        this.height=height;
        this.width=width;
        this.init();
    }
    
    public int getHeight() {return height;}
    public int getWidth() {return width;}
    public String[] getGameTypes() {return gameNames;}

    private SameGameRules getGameRules() {return gameRules;}
    private void setGameRules(SameGameRules gameRules) {this.gameRules = gameRules;}

    public SameGameUI_I getUI() {return myUI;}
    public void setUI(SameGameUI_I myUI) {this.myUI = myUI;}

    public Board getBoard() {return myBoard;}
    public void setBoard(Board myBoard) {this.myBoard = myBoard;}

    public HighScores[] getHighScores() {return highScores;}
    public void setHighScores(HighScores[] highScores) {this.highScores = highScores;}

    public String[] getBlockNames() {return blockNames;}

    public String[] getActiveBlockNames() {return activeBlockNames;}
    public void setActiveBlockNames(String[] names) {activeBlockNames=names;}

    public int[] getBlockLimits() {return blockLimit;}
    public void setBlockLimits(int[] limits) {blockLimit=limits;}

    public String getGameName(){return gameNames[activeGameID];}
    public void setGameNameID (int gameID){activeGameID=gameID;}

    public void resetBlockLimit(){
        blockLimit=new int[blockNames.length];
        for (int i=0; i<blockLimit.length;++i)
            blockLimit[i]=height*width;
    }
    
    @Override
    public String toString(){
        return ""+this.score+FILE_DELIMITER+this.parcialScore+FILE_DELIMITER+
                "\n"+this.width+FILE_DELIMITER+this.height+FILE_DELIMITER;
    }

    /*
     * métodos para actualizar os Scores
     */
    public void setScores(int s1, int s2){score=s1;parcialScore=s2;}
    public int getScore(){return score;}
    public int getParcialScore(){return parcialScore;}
    public void resetScores(){score=0; parcialScore=0;}
    public void updateScore() {score+=parcialScore; parcialScore=0;}
    public void setParcialScore(int s){this.parcialScore=s;}



    public final void init(){
        //prepara acesso aos ficheiros gravados
        file = new FileAccess(this);
        //recolhe as classes acessíveis para criar os jogos e os blocos
        blockNames = file.getFileNames(BLOCKS_PACKAGE);
        gameNames = file.getFileNames(GAMETYPE_PACKAGE);

        //cria o array para os highscores e inicializa cada um deles
        highScores = new HighScores[gameNames.length];
        initAllHighScores();

        //lê jogo previamente gravado e suas opções
        if (!file.readAll())
            fileAccessError();
        
        //cria uma nova instância de board
        //myBoard = new Board(height, width, activeBlockNames,blockLimit,false);







        //DEBUG
        //activeGameID=0;
        score=parcialScore=0;

    }

    public void newGame() {
        myBoard.init();
        this.run();
    }

    public boolean saveGame(){return file.saveGame();}
    public boolean saveHighScores(){return file.saveHighScores();}
    public boolean saveAll(){return file.saveAll();}

    public void initAllHighScores(){
        for (int i=0; i<highScores.length; ++i)
            highScores[i]= new HighScores();
    }
    public void resetAllHighScores(){
        for (int i=0; i<highScores.length; ++i)
            resetHighScore(i);
    }
    public void resetHighScore(int i){
        highScores[i].reset();
    }

    private void fileAccessError(){
        //DEBUG
        System.out.println("Erro ao aceder aos ficheiros!");
    }

    public void clickedBlock(int x, int y) {
        gameRules.clickedBlock(x, y);
    }

    public void rotateBoard(boolean right){
        gameRules.rotateBoard(right);
    }


    public void run(){

    
    }





}
