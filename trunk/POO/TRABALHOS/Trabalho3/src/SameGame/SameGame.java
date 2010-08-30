/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame;

import SameGame.Game.*;
import SameGame.Game.model.*;
import SameGame.GaSme.model.blocks.*;

import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author Nuno
 */
public class SameGame implements GameModelVars_I{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        FileAccess file= new FileAccess();
        SameGameEngine eng = new SameGameEngine(5,5);
        eng.newGame();
        System.out.println(eng.getBoard().toStringDebug());
        eng.getBoard().select(2, 0);
        System.out.println(eng.getBoard().toStringDebug());
        eng.getBoard().removeSelected();
        System.out.println(eng.getBoard().toStringDebug());
        //eng.getBoard().rotate(true);
        //System.out.println(eng.getBoard().toStringDebug());

    }
}
