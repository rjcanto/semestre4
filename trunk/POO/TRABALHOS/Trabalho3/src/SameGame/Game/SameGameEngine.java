/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game;

import SameGame.Game.model.Board;
import java.util.logging.Level;
import java.util.logging.Logger;

public class SameGameEngine extends SameGameEngineAbstract implements SameGameVars_I {

    public SameGameEngine(int height, int width){
        super(height,width);
        this.initEngine();
    }

    public final void initEngine(){
        //prepara acesso aos ficheiros gravados
        setFile(new FileAccess());
        getFile().setEngine(this);
        //recolhe as classes acessíveis para criar os jogos e os blocos
        setBlockNames(getFile().getFileNames(BLOCKS_PACKAGE));
        setGameNames(getFile().getFileNames(GAMETYPE_PACKAGE));
        if (getBlockNames()==null || getGameNames()==null){
            logError("Erro ao obter os " + ((getBlockNames()==null)?"blocos!":"tipos de jogo!"));
            System.exit(0);
        }
        //inicializa cada um deles
        initAllHighScores();
        //lê jogo previamente gravado e suas opções
        if (!getFile().loadAll())
            fileErrorAnalyzer(getFile().getErrorCode());
        newGame(true);
    }
    /*
     * método para inicializar os limites dos blocos para o caso de
     * ocorrer um erro de leitura do ficheiro
     */
    private void resetBlockLimit(){
        int[] bl=new int[getBlockNames().length];
        int max = getHeight()*getWidth();
        for (int i=0; i<bl.length;++i)
            bl[i]=max;
        updateBlockLimits(bl);
    }
    
    @Override
    public String toString(){
        return ""+getScore()+FIELD_DELIMITER+getParcialScore()+FIELD_DELIMITER+
                "\n"+getWidth()+FIELD_DELIMITER+getHeight()+FIELD_DELIMITER;
    }

    /*
     * métodos para actualizar os Scores
     */
    @Override
    public void setScores(int s1, int s2){
        super.setScores(s1, s2);
        setChanged();
        notifyObservers();
    }
    @Override
    public void setParcialScore(int s){
        super.setParcialScore(s);
        setChanged();
        notifyObservers();
    }

    public void undoMove(){
        getBoard().loadState(this);
        getBoard().unselect();
        //getGameRules().setParcialScore(getBoard().getNumberSelectedBlocks());
        setChanged();
        notifyObservers();
    }

    /*acesso a ficheiros para load e save dos jogos*/
    public boolean loadGame(){return getFile().loadSavedGame();}
    public boolean loadHighScores(){return getFile().loadHighScores();}
    public boolean loadOptions(){return getFile().loadGameOptions();}
    public boolean loadAll(){return getFile().loadAll();}

    public boolean saveGame(){return getFile().saveGame();}
    public boolean saveHighScores(){return getFile().saveHighScores();}
    public boolean saveOptions(){return getFile().saveGameOptions();}
    public boolean saveAll(){return getFile().saveAll();}

    private void fileErrorAnalyzer(int error){
        if (error==0) return;
        if((ERROR_OPTIONS)<=error){
            logError("Erro ao ler as opções do jogo gravadas.");
            updateGameType(0);
            resetBlockLimit();
            error%=ERROR_OPTIONS;
        }
        if((ERROR_SAVEGAME)<=error){
            logError("Erro ao ler o jogo gravado.");
            if (getBoard()==null)
                setBoard(new Board(getHeight(), getWidth(), getBlockNames(), getBlockLimits(), false));
            getBoard().initBoard(getBlockLimits());
            error%=ERROR_SAVEGAME;
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

    @Override
    public void exit(){
        this.saveAll();
        System.exit(0);
    }
    public void clickedBlock(int x, int y) {
        getGameRules().clickedBlock(x, y);
        setChanged();
        notifyObservers();
    }
    public void resetRotateLimit(){setRotateLimit(ROTATE_LIMIT);}

    public void rotateBoard(boolean right){
        if (getRotateLimit()==0 || getRemainingBlocks()==0)
            return;
        getGameRules().rotateBoard(right);
        decRotateLimit();
        setChanged();
        notifyObservers();
    }
    
    public void newGame(boolean continueGame) {
        resetRotateLimit();
        updateGameType();
        updateBlockLimits();
        try{
            setGameRules((SameGameRules) Class.forName("SameGame.Game.gameType."+getGameNames()[getGameType()]).
                    getDeclaredConstructor(SameGameEngine.class).newInstance(this));
        } catch(Exception ex){
            Logger.getLogger(Board.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            System.exit(0);
        }
        /* se está a continuar um jogo (jogo gravado) verifica se o jogo
         * já tinha terminado antes de gravar.
         */
        if (!continueGame && isContinuous())
            verifyHighScores();
        
        if (continueGame && verifyStuck()){
            gameFinished();
        }
        else{
            gameStarted();
            resetRotateLimit();
        }
        
        if (!continueGame){
            getBoard().initBoard(getBlockLimits());
            resetScores();
        }
        setChanged();
        notifyObservers();
    }

    public boolean verifyEnd(){
        if (!getGameRules().isContinuous())
            if (getGameRules().verifyStuck()){
                gameFinished();
                if (getGameRules().verifyWin())
                    getGameRules().addWinBonus();
                verifyHighScores();
                return true;
            }
        return false;
    }

    private void verifyHighScores(){
        if (isHighScore()){
            addHighScore(getUI().getHighScoreName());
            getUI().showHighScores(getHighScores());
        }
    }
}
