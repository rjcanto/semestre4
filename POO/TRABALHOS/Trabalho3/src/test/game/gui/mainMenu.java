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
        /* Menu Game */
        JMenu game = new JMenu("Game");
        JMenuItem newGame = new JMenuItem("New");
        JMenuItem exit = new JMenuItem("Exit");
        exit.addActionListener(new exitAction());
        game.add(newGame);
        game.add(exit);

        /* Menu Game */
        JMenu options = new JMenu("Options");
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

        /* Menu Layout */
        JMenu layout = new JMenu("Layout");
        JMenuItem l1 = new JMenuItem("Layout 1");
        JMenuItem l2 = new JMenuItem("Layout 2");
        layout.add(l1);
        layout.add(l2);

        /* Menu Blocks */
        JMenu blockshape = new JMenu("BlockShape");
        JMenuItem b1 = new JMenuItem("CircleBlock");
        JMenuItem b2 = new JMenuItem("RubiBlock");
        JMenuItem b3 = new JMenuItem("SquareBlcok");
        JMenuItem b4 = new JMenuItem("StarBlock");
        JMenuItem b5 = new JMenuItem("TriangleBlock");
        blockshape.add(b1);
        blockshape.add(b2);
        blockshape.add(b3);
        blockshape.add(b4);
        blockshape.add(b5);


        /* Menu Help */
        JMenu help = new JMenu ("Help");
        JMenuItem rules = new JMenuItem("Rules");
        JMenuItem about = new JMenuItem("About");
        help.add(rules);
        help.add(about);

        /* add all menus items to bar */
        add(game);
        add(options);
        add(layout);
        add(blockshape);
        add(help);

    }
    class exitAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
