/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game;

import SameGame.Game.model.Board;
import SameGame.Game.gui.SameGameUI_I;
import SameGame.Game.model.Block;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JPanel;

/**
 *
 * @author Nuno
 */
public class SameGameEngine extends SameGameEngineAbstract implements SameGameEngine_I, SameGameVars_I {
    private Board myBoard;
    private SameGameUI_I myUI;
    private SameGameRules gameRules;

    private HighScores[] highScores;
    private FileAccess file;

    private String[] gameNames;
    private int activeGameID;
    private int nextGameID;

    private String[] blockNames;
    private int[] blockLimit;
    private int[] nextBlockLimit;

    private String layoutName;
    private String blockShapeName;

    private int width;
    private int height;
    private int score;
    private int parcialScore;

    public SameGameEngine(int height, int width){
        this.height=height;
        this.width=width;
        this.initEngine();
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
    public void setBlockNames(String[] names) {blockNames=names;}

    public int[] getBlockLimits() {return blockLimit;}
    public void setBlockLimits(int[] limits) {nextBlockLimit=limits;}

    public String getLayoutName() {return layoutName;}
    public void setLayoutName(String name) {layoutName=name;}
    public String getBlockShapeName() {return blockShapeName;}
    public void setBlockShapeName(String name) {blockShapeName=name;}

    public int getActiveGameType() {return activeGameID;}
    public void setGameType(int gameID) {nextGameID=gameID;}
     
    private void resetBlockLimit(){
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
    public void setScores(int s1, int s2){
        score=s1;parcialScore=s2;
        setChanged();
        notifyObservers();
    }
    public int getScore(){return score;}
    public int getParcialScore(){return parcialScore;}
    public void resetScores(){setScores(0,0);}
    public void updateScore() {setScores(score+parcialScore,0);}
    public void setParcialScore(int s){
        this.parcialScore=s;
        setChanged();
        notifyObservers();
    }

    public void initAllHighScores(){
        for (int i=0; i<highScores.length; ++i)
            highScores[i]= new HighScores();
    }
    public void clearAllHighScores(){
        for (int i=0; i<highScores.length; ++i)
            clearHighScore(i);
    }
    public void clearHighScore(int i){highScores[i].clearHighScores();}

    public int getRemainingBlocks(){return myBoard.getRemainingBlocks();}
    public void undoMove(){
        this.setScores(myBoard.loadState(), 0);
        gameRules.setParcialScore(myBoard.getNumberSelectedBlocks());
        setChanged();
        notifyObservers();
    }

    public boolean saveGame(){return file.saveGame();}
    public boolean saveHighScores(){return file.saveHighScores();}
    public boolean saveOptions(){return file.saveGameOptions();}
    public boolean saveAll(){return file.saveAll();}

    public void exit(){
        this.saveAll();
        System.exit(0);
    }

    private void fileErrorAnalyzer(int error){
        if (error==0) return;
        if((ERROR_SAVEGAME)<=error){
            logError("Erro ao ler o jogo gravado.");
            if (myBoard==null)
                myBoard = new Board(height, width, blockNames, blockLimit, false);
            myBoard.initBoard();
            error%=ERROR_SAVEGAME;
        }
        if((ERROR_OPTIONS)<=error){
            logError("Erro ao ler as opções do jogo gravadas.");
            activeGameID=0;
            resetBlockLimit();
            error%=ERROR_OPTIONS;
        }
        if((ERROR_HIGHSCORES)<=error){
            logError("Erro ao ler os High Scores.");
            initAllHighScores();
            error%=ERROR_HIGHSCORES;
        }
        System.out.println("Erro ao aceder aos ficheiros!");
    }

    private void logError(String error){
        System.out.println(error);
        Logger.getLogger(SameGameEngine.class.getName()).log(Level.SEVERE, null, new ClassNotFoundException(error));
    }
    public void clickedBlock(int x, int y) {
        gameRules.clickedBlock(x, y);
        setChanged();
        notifyObservers();
    }

    public void rotateBoard(boolean right){
        gameRules.rotateBoard(right);
        setChanged();
        notifyObservers();
    }
    public Block getBlock(int r, int c){return myBoard.getBlock(r, c);}

    public final void initEngine(){
        //prepara acesso aos ficheiros gravados
        file = new FileAccess();
        file.setEngine(this);
        //recolhe as classes acessíveis para criar os jogos e os blocos
        blockNames = file.getFileNames(BLOCKS_PACKAGE);
        gameNames = file.getFileNames(GAMETYPE_PACKAGE);
        if (blockNames==null || gameNames==null){
            logError("Erro ao obter os " + ((blockNames==null)?"blocos!":"tipos de jogo!"));
            System.exit(0);
        }
        //cria o array para os highscores e inicializa cada um deles
        highScores = new HighScores[gameNames.length];
        initAllHighScores();
        //lê jogo previamente gravado e suas opções
        if (!file.readAll())
            //fileErrorAnalyzer(file.getErrorCode());
        score=parcialScore=0;
        newGame(true);
    }


    public void newGame(boolean continueGame) {
        activeGameID = nextGameID;
        blockLimit = nextBlockLimit;
        try{
            gameRules = (SameGameRules) Class.forName("SameGame.Game.gameType."+gameNames[activeGameID]).
                    getDeclaredConstructor(SameGameEngine.class).newInstance(this);
        } catch(Exception ex){
            Logger.getLogger(Board.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            System.exit(0);
        }
        if (!continueGame){
            myBoard.initBoard();
            resetScores();
        }
        setChanged();
        notifyObservers();
    }

    public void verifyEnd(){
        if (gameRules.verifyStuck()){
            if (gameRules.verifyWin())
                gameRules.addWinBonus();
//            if (highScores[activeGameID].isHighScore(getScore())){
//                highScores[activeGameID].add(myUI.getHighScoreName(), score);
//                myUI.showHighScores(highScores[activeGameID]);
//                }
          }

    }
}
