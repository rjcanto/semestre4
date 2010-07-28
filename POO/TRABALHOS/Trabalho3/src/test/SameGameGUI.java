
package test;
import java.awt.*;
import java.applet.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 *
 * @author Nuno
 */
public class SameGameGUI implements SameGameUI_I, ActionListener{

    public SameGameGUI(int width, int height){
        createAndShowGUI(width, height);





    }

    private void createAndShowGUI(int width, int height) {
        JFrame main = new JFrame("SameGame");
        main.setSize(800, 600);
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        

        JPanel board = new JPanel(new GridLayout(height, width));


        main.getContentPane().add(board, BorderLayout.CENTER);



        /*criacao dos menus do jogo*/
        JMenuBar menuBar = new JMenuBar();
        main.setJMenuBar(menuBar);
        JMenu game = new JMenu("Game");
        menuBar.add(game);
        JMenuItem newGame = new JMenuItem("New");
        JMenuItem exit = new JMenuItem("Exit");
        exit.addActionListener(new exitAction());
        game.add(newGame);
        game.add(exit);

        JMenu options = new JMenu("Options");
        menuBar.add(options);

        JRadioButtonMenuItem grav = new JRadioButtonMenuItem("Gravitational");
        JRadioButtonMenuItem megaGrav = new JRadioButtonMenuItem("Mega Gravitational");
        JRadioButtonMenuItem shifter = new JRadioButtonMenuItem("Shifter");
        JRadioButtonMenuItem megaShifter = new JRadioButtonMenuItem("Mega Shifter");
        ButtonGroup btnGroup = new ButtonGroup();
        btnGroup.add(grav);
        btnGroup.add(megaGrav);
        btnGroup.add(shifter);
        btnGroup.add(megaShifter);
        options.add(grav);
        options.add(megaGrav);
        options.add(shifter);
        options.add(megaShifter);

        

        JMenu help = new JMenu ("Help");
        menuBar.add(help);
        JMenuItem rules = new JMenuItem("Rules");
        JMenuItem about = new JMenuItem("About");
        help.add(rules);
        help.add(about);







        //main.pack();
        main.setVisible(true);
    }
    public void setController(SameGameEngine_I c) {
        throw new UnsupportedOperationException("Not supported yet.");
    }






    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet.");
    }



    class exitAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
