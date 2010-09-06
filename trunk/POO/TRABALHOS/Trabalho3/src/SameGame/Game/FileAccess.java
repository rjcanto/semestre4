/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game;

import SameGame.Game.model.Board;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URL;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import sun.misc.Launcher;

/**
 *
 * @author Nuno
 */
public class FileAccess implements SameGameVars_I{

    File saveGame;
    File highScore;
    File gameoptions;
    SameGameEngine_I eng;
    int error_code;
    
    public FileAccess(){
        saveGame = getFile(SAVE_PATH+"\\"+SAVEGAME_FILENAME);
        highScore = getFile(SAVE_PATH +"\\"+HIGHSCORES_FILENAME);
        gameoptions = getFile(SAVE_PATH +"\\"+GAME_OPTIONS_FILENAME);
        error_code=0;
    }
    public void setEngine(SameGameEngine_I engine){eng=engine;}
    /*
     * Retorna o código de erro (soma dos vários erros que podem ter ocorrido)
     * @return valor do código de erro
     */
    public int getErrorCode(){return error_code;}
    private void setErrorCode(int e){error_code+=e;}
    
    private File getFile(String string) {return new File(string);}

    /*
     * Pesquisa dentro do package pack as classes existente para poderem ser
     * inicializadas
     * @param pack String com o nome do package a analisar
     * @return Array de strings com os nomes das classes do package
     */
    public String[] getFileNames(String pack) {
        /*tranformar o nome do package no path relativo do mesmo*/
        String path="";
        if (!pack.startsWith("/")) {
            path = "/" + pack;
        }
        path = path.replace('.','/');
        /*obter o path absoluto do package*/
        URL url = Launcher.class.getResource(path);
        File directory = new File(url.getFile());
        String[] classesFound = directory.list();
        /*retirar o .class do nome dos ficheiros*/
        for (int i=0; i<classesFound.length;++i)
            classesFound[i]=classesFound[i].substring(0,classesFound[i].length()-6);
        return classesFound;
    }





    public boolean readAll(){
        return (readGameOptions() && readSavedGame() & readHighScores());
    }

    /*
     * Ler jogo gravado
     */
    public boolean readSavedGame(){
        if (saveGame.exists())
            if(importSaveGame())
                return true;
        setErrorCode(ERROR_SAVEGAME);
        return false;
     }
    private boolean importSaveGame(){
        try {
            if (!getSaveGame(new BufferedReader(new FileReader(saveGame))))
                return false;
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    /*
     * <gametype>;
     * <score>;<parcialScore>;
     * <rows>;<columns>;
     * <BOARD>;
     */
    private boolean getSaveGame(BufferedReader bf) throws IOException, NoSuchElementException{
        StringTokenizer strtok = new StringTokenizer(bf.readLine(),FILE_DELIMITER);
        eng.setScores(Integer.parseInt(strtok.nextToken()),
                            Integer.parseInt(strtok.nextToken()));

        return getBoard(bf);
    }

    private boolean getBoard(BufferedReader bf) throws IOException, NoSuchElementException{
        boolean success = true;
        String blockNames[] = eng.getBlockNames();
        StringTokenizer strtok = new StringTokenizer(bf.readLine(),FILE_DELIMITER);
        Board board = new Board(Integer.parseInt(strtok.nextToken()),
                Integer.parseInt(strtok.nextToken()),blockNames,eng.getBlockLimits(),false);
        eng.setBoard(board);
        for (int r=0; r<board.getHeight() && success;++r){
            strtok = new StringTokenizer(bf.readLine(),FILE_DELIMITER);
            for (int c=0; c<board.getWidth() && success;++c){
                String name=strtok.nextToken();
                int type;
                if (!name.equalsIgnoreCase(" ") && (type=checkBlockType(name, blockNames))!=-1)
                    success = board.addBlock(name, type, Integer.parseInt(strtok.nextToken()), r, c);
            }
        }
        return success;
    }
    private int checkBlockType(String name, String[] gameTypes) {
        for (int i=0;i<gameTypes.length;++i)
            if (name.equalsIgnoreCase(gameTypes[i]))
                return i;
        return -1;
    }

    /*
     * Ler High Scores
     */
    public boolean readHighScores(){
        if (saveGame.exists()){
            return importHighScores();
        }
        setErrorCode(ERROR_HIGHSCORES);
        return false;
    }

    private boolean importHighScores(){
        try {
            if (getHighScores(new BufferedReader(new FileReader(highScore))))
                return true;
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return false;
    }
    

    /*
     * <Gametype>;<num de linhas>;
     * <HighScore.toString>;
     * <Gametype>;<num de linhas>;
     * <HighScore.toString>;
     * ...
     * ...
     */
    private boolean getHighScores(BufferedReader bf) throws IOException, NoSuchElementException{
        String line,name;
        int numberLines, gameTypeidx;
        int maxGameTypeidx = eng.getGameTypes().length-1;

        eng.initAllHighScores();
        while((line = bf.readLine())!=null){
            StringTokenizer strtok = new StringTokenizer(line,FILE_DELIMITER);
            name = strtok.nextToken();
            numberLines = Integer.parseInt(strtok.nextToken());
            if ((gameTypeidx = checkGameType(name,eng.getGameTypes()))==-1){
                addHS(bf, eng.getHighScores()[maxGameTypeidx--], numberLines);
            }else{
                addHS(bf, eng.getHighScores()[gameTypeidx], numberLines);
            }
        }
        return true;
    }
    private int checkGameType(String name, String[] gameTypes) {
        for (int i=0;i<gameTypes.length;++i)
            if (name.equalsIgnoreCase(gameTypes[i]))
                return i;
        return -1;
    }
    private void addHS(BufferedReader bf, HighScores hs, int num) throws IOException, NoSuchElementException{
        for (int i=0; i<num;++i){
            StringTokenizer strtok = new StringTokenizer(bf.readLine(),FILE_DELIMITER);
            hs.add(strtok.nextToken(), Integer.parseInt(strtok.nextToken()));
        }
    }

    /*
     * Ler Opções do jogo
     */
    public boolean readGameOptions(){
        if (gameoptions.exists()){
            return importGameOptions();
        }
        setErrorCode(ERROR_OPTIONS);
        return false;
    }
    private boolean importGameOptions(){
        try {
            if (!getGameOptions(new BufferedReader(new FileReader(gameoptions))))
                return false;
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    /*
     * <Gametype>;
     * <number of active blocks>;
     * <BlockName>;<maxAmmount>;
     * <BlockName>;<maxAmmount>;
     * ...
     */
    private boolean getGameOptions(BufferedReader bf) throws IOException, NoSuchElementException{
        String line;
        int numberBlocks;

        //le o tipo de jogo gravado
        eng.setGameType(checkGameType(bf.readLine(), eng.getGameTypes()));
        numberBlocks = Integer.parseInt(bf.readLine());
        String[] blockNames = new String[numberBlocks];
        int[] blockLimits = new int[numberBlocks];
        int i=0;
        while((line = bf.readLine())!=null && i<numberBlocks){
            StringTokenizer strtok = new StringTokenizer(line, FILE_DELIMITER);
            blockNames[i]=strtok.nextToken();
            blockLimits[i++]=Integer.parseInt(strtok.nextToken());
        }
        eng.setBlockNames(blockNames);
        eng.setBlockLimits(blockLimits);
        StringTokenizer strtok = new StringTokenizer(line, FILE_DELIMITER);
        eng.setLayoutName(strtok.nextToken());
        eng.setBlockShapeName(strtok.nextToken());

        return (i==numberBlocks);
}


    /*
     * métodos para escrita nos ficheiros
     */
    public boolean saveAll(){
        return (saveGame() & saveHighScores() & saveGameOptions());
    }
    public boolean saveGame(){
        if (!saveGame.exists())
            try {
            saveGame.createNewFile();
            } catch (IOException ex) {
                Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }
        return exportSaveGame();
    }
    private boolean exportSaveGame(){
        try {
            putSaveGame(new PrintWriter(new FileWriter(saveGame)));
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    private void putSaveGame(PrintWriter pw) throws IOException{
        pw.println(eng.getScore()+FILE_DELIMITER+eng.getParcialScore()+FILE_DELIMITER);
        pw.println(eng.getHeight()+FILE_DELIMITER+eng.getWidth()+FILE_DELIMITER);
        pw.print(eng.getBoard().toString());
        pw.flush();
        pw.close();
    }

    public boolean saveHighScores(){
        if (!highScore.exists())
            try {
            highScore.createNewFile();
            } catch (IOException ex) {
                Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }
        return exportHighScores();
    }
    private boolean exportHighScores(){
        try {
            putHighScores(new PrintWriter(new FileWriter(highScore)));
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    private void putHighScores(PrintWriter pw) throws IOException {
       for(int i=0;i<eng.getHighScores().length;++i){
           pw.println(eng.getGameTypes()[i]+FILE_DELIMITER+
                   eng.getHighScores()[i].getSize()+FILE_DELIMITER);
           pw.print(eng.getHighScores()[i].toString());
       }
       pw.flush();
       pw.close();
    }

    public boolean saveGameOptions(){
        if (!gameoptions.exists())
            try {
            gameoptions.createNewFile();
            } catch (IOException ex) {
                Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }
        return exportGameOptions();
    }
    private boolean exportGameOptions(){
        try {
            putGameOptions(new PrintWriter(new FileWriter(gameoptions)));
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    private void putGameOptions(PrintWriter pw) throws IOException{
        pw.println(eng.getGameTypes()[eng.getActiveGameType()]);
        pw.println(eng.getBlockNames().length);
        for (int i=0; i<eng.getBlockNames().length;++i)
            pw.println(eng.getBlockNames()[i]+FILE_DELIMITER+
                    eng.getBlockLimits()[i]+FILE_DELIMITER);
        pw.println(eng.getLayoutName()+FILE_DELIMITER+eng.getBlockShapeName()+FILE_DELIMITER);
        pw.flush();
        pw.close();
    }






}
