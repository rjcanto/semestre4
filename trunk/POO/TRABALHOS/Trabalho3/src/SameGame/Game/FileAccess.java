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
    public FileAccess(){
        saveGame = getFile(SAVEGAME_PATH+"\\"+SAVEGAME_FILENAME);
        highScore = getFile(SAVEGAME_PATH +"\\"+HIGHSCORES_FILENAME);
    }
    private File getFile(String string) {return new File(string);}

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

    public boolean readAll(SameGameEngine eng){
        return (readSavedGame(eng) & readHighScores(eng));
    }

    public boolean readSavedGame(SameGameEngine eng){
        if (saveGame.exists())
            if(importSaveGame(eng,eng.getBoard()))
                return true;
        eng.getBoard().init();
        return false;
     }

    public boolean readHighScores(SameGameEngine eng){
        for (int i=0;i<eng.getHighScores().length;++i)
            eng.getHighScores()[i].initHighScores();
        if (saveGame.exists()){
            return importHighScores(eng);
        }
        return false;
    }
    
    private boolean importSaveGame(SameGameEngine eng, Board b){
        try {
            if (!getSaveGame(new BufferedReader(new FileReader(saveGame)),eng))
                return false;
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }

    private boolean importHighScores(SameGameEngine eng){
        try {
            if (!getHighScores(new BufferedReader(new FileReader(highScore)),eng))
                return false;
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }
    
/*
 * <score>;<parcialScore>;
 * <rows>;<columns>;
 * <BOARD>;
 */
    private boolean getSaveGame(BufferedReader bf, SameGameEngine eng) throws IOException{
        StringTokenizer strtok = new StringTokenizer(bf.readLine());
        eng.setScores(Integer.parseInt(strtok.nextToken()),
                            Integer.parseInt(strtok.nextToken()));
        return getBoard(bf,eng.getBoard().getBlockNames());
    }

    private boolean getBoard(BufferedReader bf, String[] blockNames) throws IOException{
        boolean success = true;
        StringTokenizer strtok = new StringTokenizer(bf.readLine());
        Board board = new Board(Integer.parseInt(strtok.nextToken()),
                Integer.parseInt(strtok.nextToken()),blockNames,false);
        for (int r=0; r<board.getHeight() && success;++r)
            for (int c=0; c<board.getWidth() && success;++c){
                String name=strtok.nextToken();
                int type;
                if (!name.equalsIgnoreCase(" ") && (type=checkBlockType(name, blockNames))!=-1)
                    success = board.addBlock(name, type, Integer.parseInt(strtok.nextToken()), r, c);
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
     * <Gametype>;<num de linhas>;
     * <HighScore.toString>;
     * <Gametype>;<num de linhas>;
     * <HighScore.toString>;
     * ...
     * ...
     */
    private boolean getHighScores(BufferedReader bf,SameGameEngine eng) throws IOException {
        String line,name;
        int numberLines, gameTypeidx;
        boolean success=true;

        while((line = bf.readLine())!=null){
            StringTokenizer strtok = new StringTokenizer(line);
            name = strtok.nextToken();
            numberLines = Integer.parseInt(strtok.nextToken());
            if ((gameTypeidx = checkGameType(name,eng.getGameType()))==-1){
                for(int i=0; i<numberLines;++i)
                    bf.readLine();
                success=false;
            }else{
                addHS(bf, eng.getHighScores()[gameTypeidx], numberLines);
            }
        }
        return success;
    }
    private int checkGameType(String name, String[] gameTypes) {
        for (int i=0;i<gameTypes.length;++i)
            if (name.equalsIgnoreCase(gameTypes[i]))
                return i;
        return -1;
    }
    private void addHS(BufferedReader bf, HighScores hs, int num) throws IOException{
        for (int i=0; i<num;++i){
            StringTokenizer strtok = new StringTokenizer(bf.readLine());
            hs.addHighScore(strtok.nextToken(), Integer.parseInt(strtok.nextToken()));
        }
    }


    /*
     * métodos para escrita nos ficheiros
     */
    public boolean saveAll(SameGameEngine eng){
        return (saveGame(eng) & saveHighScores(eng));
    }
    public boolean saveGame(SameGameEngine eng){
        if (!saveGame.exists())
            try {
            saveGame.createNewFile();
            } catch (IOException ex) {
                Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }
        return exportSaveGame(eng,eng.getBoard());
    }

    public boolean saveHighScores(SameGameEngine eng){
        if (!highScore.exists())
            try {
            highScore.createNewFile();
            } catch (IOException ex) {
                Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }
        return exportHighScores(eng);
    }

    private boolean exportSaveGame(SameGameEngine eng, Board b){
        try {
            putSaveGame(new PrintWriter(new FileWriter(saveGame)),eng);
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }

    private boolean exportHighScores(SameGameEngine eng){
        try {
            putHighScores(new PrintWriter(new FileWriter(highScore)),eng);
        } catch (Exception ex) {
            Logger.getLogger(FileAccess.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return true;
    }

    private void putSaveGame(PrintWriter pw, SameGameEngine eng) throws IOException{
        pw.println(eng.toString());
        pw.println(eng.getBoard().toString());
        pw.flush();
        pw.close();
    }

    private void putHighScores(PrintWriter pw,SameGameEngine eng) throws IOException {
       for(int i=0;i<eng.getHighScores().length;++i){
           pw.println(eng.getGameType()[i]+eng.getHighScores()[i].getSize());
           eng.getHighScores()[i].toString();
       }
    }
}
