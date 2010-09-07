/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gui;

import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JFrame;

/**
 *
 *
 */
public class mainWindow extends JFrame implements WindowListener{
    SameGameUI_I myUI;
    private int defaultW    =   640;
    private int defaultH    =   480;
    public mainWindow(SameGameUI_I ui){
        myUI = ui;
        create(defaultW, defaultH);
    }
    public mainWindow(int width, int height, SameGameUI_I ui){
        myUI = ui;
        create(width, height);
    }
     private void create(int width, int height) {
         setSize(width, height);
         setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
         this.addWindowListener(this);

         //setVisible(true);
     }
     public void showGUI(){
         setVisible(true);
     }

    public void windowOpened(WindowEvent e) {}

    public void windowClosing(WindowEvent e) {
        myUI.exit();
    }

    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}

}
