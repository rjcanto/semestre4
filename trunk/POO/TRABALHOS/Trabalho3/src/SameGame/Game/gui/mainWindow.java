/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import javax.swing.JFrame;

/**
 *
 * @author nac
 */
public class mainWindow extends JFrame{
    private int defaultW    =   640;
    private int defaultH    =   480;
    public mainWindow(){
        create(defaultW, defaultH);
    }
    public mainWindow(int width, int height ){
        create(width, height);
    }
     private void create(int width, int height) {
         setSize(width, height);
         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         //setVisible(true);
     }
     public void showGUI(){
         setVisible(true);
     }

}
