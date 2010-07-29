/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.gui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;

/**
 *
 * @author nac
 */
public class mainMenu extends JMenuBar {
    public mainMenu(){
        JMenu game = new JMenu("Game");
        add(game);
        JMenuItem newGame = new JMenuItem("New");
        JMenuItem exit = new JMenuItem("Exit");
        exit.addActionListener(new exitAction());
        game.add(newGame);
        game.add(exit);

        JMenu options = new JMenu("Options");
        add(options);

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
        add(help);
        JMenuItem rules = new JMenuItem("Rules");
        JMenuItem about = new JMenuItem("About");
        help.add(rules);
        help.add(about);
    }
    class exitAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
