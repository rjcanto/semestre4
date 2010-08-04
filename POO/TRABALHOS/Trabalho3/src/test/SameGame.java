/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test;
import java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import test.game.gui.CenterPanel;
import test.game.gui.InfoPanel;
import test.game.gui.FramePanel;
import test.game.gui.mainMenu;
import test.game.gui.mainWindow;

/**
 *
 * @author Nuno
 */
public class SameGame {

    /**
     * @param args the command line arguments
     */
    /*
    public static void main(String[] args) {

//        Block b = new BBlock();
//        System.out.println(b.getType());
//        System.out.println(b.getColor());
//        System.out.println(b.isSelected());
//        b = new WBlock();
//        b.select();
//        System.out.println(b.getType());
//        System.out.println(b.getColor());
//        System.out.println(b.isSelected());
    
        //SameGameGUI sg = new SameGameGUI(5,5);
        Board board = new Board(10,10);
        board.print();
        System.out.println(board.getRemainingBlocks());
        board.removeBlock(1, 1);
        board.removeBlock(2, 1);
        board.removeBlock(3, 1);
        board.removeBlock(4, 1);
        board.removeBlock(5, 1);
        board.removeBlock(6, 1);
        board.removeBlock(7, 1);
        board.removeBlock(8, 1);
        board.removeBlock(1, 1);
                board.print();
                System.out.println();
        board.removeBlock(3, 1);
        board.removeBlock(4, 1);
        board.removeBlock(5, 1);
        board.removeBlock(6, 1);
        board.removeBlock(1, 3);
        board.removeBlock(1, 2);
        board.removeBlock(1, 1);
        board.removeBlock(1, 8);
                board.print();
                System.out.println();
        board.removeBlock(1, 9);
        board.removeBlock(1, 8);
        board.removeBlock(1, 8);
        board.removeBlock(1, 8);
        board.removeBlock(1, 8);
        board.removeBlock(1, 8);
        board.removeBlock(1, 9);
        board.print();
        
        System.out.println(board.getRemainingBlocks());


        



    }
*/
    public static void main(String[] args) {
        Dimension screenSize    = Toolkit.getDefaultToolkit().getScreenSize();
        JFrame gameFrame    = new mainWindow(800,600);
        JMenuBar gameMenu       = new mainMenu();
        JPanel gamePanel        = new FramePanel();
        JPanel center           = new CenterPanel();
        JPanel info             = new InfoPanel();
        
        

        gameFrame.setJMenuBar(gameMenu);
        gamePanel.setLocation(0,0);
        center.setLocation(0, 0);
        info.setLocation(600,0);

        

        
        gameFrame.getContentPane().add(center);
        gameFrame.getContentPane().add(info);
        gameFrame.getContentPane().add(gamePanel);
        
        gameFrame.setResizable(false);
        gameFrame.setLocation((screenSize.width - gameFrame.getWidth())/2, (screenSize.height - gameFrame.getHeight())/2);
        gameFrame.pack();
        gameFrame.setVisible(true);
        

}
}
