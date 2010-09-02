/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame;

import SameGame.Game.*;
import SameGame.Game.model.*;


/**
 *
 * @author Nuno
 */
public class SameGame implements GameModelVars_I{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        SameGameEngine eng = new SameGameEngine(10,10);
        eng.newGame();
        System.out.println(eng.getBoard().toStringDebug());
        System.out.println(eng.getHighScores()[0].toString());
        
        eng.saveAll();

//        eng.newGame();
//        System.out.println(eng.getBoard().toStringDebug());
//        eng.getBoard().select(2, 0);
//        System.out.println(eng.getBoard().toStringDebug());
//        eng.getBoard().removeSelected();
//        System.out.println(eng.getBoard().toStringDebug());
//        //eng.getBoard().rotate(true);
//        //System.out.println(eng.getBoard().toStringDebug());





    }
}
