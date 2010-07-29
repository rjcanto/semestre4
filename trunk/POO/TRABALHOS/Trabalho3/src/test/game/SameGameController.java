/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game;

import test.game.model.Board;
import test.game.model.YMBlock;
import test.game.model.RGBBlock;
import test.game.model.BBlock;
import test.game.model.Block;
import test.game.model.WBlock;
import java.io.*;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Nuno
 */
public class SameGameController implements SameGameEngine_I {
    private Board myGrid;
    private SameGameUI_I myUI;

    private int level;
    private boolean atractor;
    private boolean continuidade;
    private final String FILE_SCORE = "highscore.dat";
    private final String FILE_SAVEGAME = "savegame.dat";
    private int MAX_VERTICAL = 3;
    private int MAX_HORIZONTAL = 3;


    public SameGameController(Board g, SameGameUI_I ui){
        FileReader fr = null;
        myGrid = g;
        myUI = ui;

        this.level = level;

        try {

            fr = new FileReader(FILE_SAVEGAME);
            BufferedReader bf = new BufferedReader(fr);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(SameGameController.class.getName()).log(Level.SEVERE, null, ex);
        } finally {
            try {
                fr.close();
            } catch (IOException ex) {
                Logger.getLogger(SameGameController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }






    }

    /* Gera uma nova matriz aleatoria com os 4 tipos de blocos distintos mas
     * aplicando a regra de no maximo exitirem MAX_VERTICAL e MAX_HORIZONTAL
     * bolcos com opções especiais
     */
    
    public void generateNew(){
       int horiz=0, vert=0;
       Random r = new Random();
       for (int i=0; i<width; ++i){
            for (int j=0; j<height; ++j){
                int k = r.nextInt(10);
                if (k<=3)
                    grid[i][j] = new RGBBlock();
                else if (k<=7)
                    grid[i][j] = new YMBlock();
                else if (k<=8){
                    if (horiz<MAX_HORIZONTAL){
                        grid[i][j] = new BBlock();
                        ++horiz;
                    }else{grid[i][j] = new RGBBlock();}
                }else{
                    if (vert<MAX_VERTICAL){
                        grid[i][j] = new WBlock();
                        ++horiz;
                    }else{grid[i][j] = new YMBlock();}
                }
            }
       }
    }
    public void setGameLevel(int level) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean selectBlock(int x, int y) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean unselectBlock(int x, int y) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public boolean unselectBlock(Block block) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public int removeSelectedBlock() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public int removeBlock(int x, int y) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public int removeBlock(Block block) {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void newGame() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

}
