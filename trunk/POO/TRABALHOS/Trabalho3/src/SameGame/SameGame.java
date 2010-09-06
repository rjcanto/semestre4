/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame;

import SameGame.Game.SameGameEngine;
import SameGame.Game.gui.Layouts.Layout2;
import SameGame.Game.gui.SameGameGUI;
import SameGame.Game.gui.mainMenu;
import SameGame.Game.gui.mainWindow;
import SameGame.Game.model.*;
import java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JPanel;


/**
 *
 * @author Nuno
 */
public class SameGame implements GameModelVars_I{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        int width=10;
        int height=10;
        SameGameEngine engine   = new SameGameEngine(height,width);
        SameGameGUI gui = new SameGameGUI(height, width, engine);


    }
}
