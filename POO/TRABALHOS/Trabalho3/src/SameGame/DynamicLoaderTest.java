/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame;

import SameGame.Game.model.Block;
import SameGame.Game.model.*;
import SameGame.Game.model.Block;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import SameGame.SameGame;

/**
 *
 * @author Nuno
 */
public class DynamicLoaderTest {





    public static void main(String[] args){

        String[] blockNames = {"BBlock","RGBBlock","WBlock","YMBlock"};
        Block block;
        try {
//            Class<?> blockClass = Class.forName("SameGame.Game.model.blocks."
//                    +blockNames[0]);

            int rand = new Random().nextInt(blockNames.length);
            block = (Block) Class.forName("SameGame.Game.model.blocks."
                    +blockNames[rand]).
                    getDeclaredConstructor(int.class).newInstance(rand);
        } catch (Exception ex) {
            System.err.println(ex);
            Logger.getLogger(SameGame.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}
