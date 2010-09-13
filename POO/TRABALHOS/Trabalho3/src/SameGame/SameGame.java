/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame;

import SameGame.Game.SameGameEngine;
import SameGame.Game.gui.SameGameGUI;


public class SameGame{

    public static void main(String[] args) {

        int width=10;
        int height=10;
        SameGameEngine engine   = new SameGameEngine(height,width);
        SameGameGUI gui = new SameGameGUI(height, width, engine);
        while(true){}
    }
}
