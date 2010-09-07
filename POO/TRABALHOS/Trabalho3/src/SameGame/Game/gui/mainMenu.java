package SameGame.Game.gui;

import SameGame.Game.SameGameEngine;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import javax.swing.ButtonGroup;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;

/**
 *
 * 
 */
public class mainMenu extends JMenuBar{

    private SameGameUI_I myUI;
    
    public mainMenu(SameGameUI_I ui){
        this.myUI = ui;
        
        /* Menu Game */
        JMenu game = new JMenu("Game");
        game.setMnemonic(KeyEvent.VK_G);
        JMenuItem newGame = new JMenuItem("New");
        newGame.setMnemonic(KeyEvent.VK_N);
        newGame.addActionListener(new newGameAction());
        JMenuItem highScores = new JMenuItem("High Scores");
        highScores.setMnemonic(KeyEvent.VK_H);
        highScores.addActionListener(new showHighScoresAction());
        JMenuItem exit = new JMenuItem("Exit");
        exit.setMnemonic(KeyEvent.VK_X);
        exit.addActionListener(new exitAction());
        game.add(newGame);
        game.add(highScores);
        game.add(exit);

        /* Menu Game Options*/
        JMenu options = new JMenu("Game Options");
        options.setMnemonic(KeyEvent.VK_O);
        JMenuItem undoMove = new JMenuItem("Undo Move");
        undoMove.setMnemonic(KeyEvent.VK_U);
        undoMove.addActionListener(new undoMoveAction());
        options.add(undoMove);
            /*Game type*/
        JMenuItem gameType = new JMenu("Game type");
        gameType.setMnemonic(KeyEvent.VK_G);
        createButtonGroup(gameType, myUI.getGameEngine().getGameNames(), myUI.getGameEngine().getGameType(), new gameTypeAction());
        options.add(gameType);
       
            /*Block Types*/
        JMenuItem blockType = new JMenuItem("Block Types");
        blockType.setMnemonic(KeyEvent.VK_B);
        blockType.addActionListener(new blockTypeAction());
        options.add(blockType);


        /* Menu View options */
        JMenu viewOpt = new JMenu("View Options");
        viewOpt.setMnemonic(KeyEvent.VK_V);

            /* Layout*/
        JMenuItem layout = new JMenu("Layout");
        layout.setMnemonic(KeyEvent.VK_L);
        createButtonGroup(layout, myUI.getLayoutNames(), 1, new layoutAction());
        viewOpt.add(layout);

            /*Block shape*/
        JMenuItem blockShape = new JMenu("Block Shape");
        blockShape.setMnemonic(KeyEvent.VK_S);
        createButtonGroup(blockShape, myUI.getBlockShapeNames(),myUI.getActiveBlockShape(),new blockShapeAction());
        viewOpt.add(blockShape);

        /* Menu Help */
        JMenu help = new JMenu ("Help");
        JMenuItem rules = new JMenuItem("Rules");
        JMenuItem about = new JMenuItem("About");
        help.add(rules);
        help.add(about);

        /* add all menus items to bar */
        add(game);
        add(options);
        add(viewOpt);
        add(help);

    }

    /*
     * Cria um RadioButtonGroup que contem todos os elemtentos de elements,
     * define o ActionListenner e o ActionCommand de cada um deles e adiciona-os
     * ao MenuItem menu
     * @param menu menu onde vão ser adicionados os radio buttons
     * @param elements array de strings com os nomes a mostrar em cada botão
     * @param selected index de elements que deve ficar seleccionado por defeito
     * @param al ActionListenner a adicionar a cada um dos botões
     */
    private void createButtonGroup(JMenuItem menu, String[] elements, int selected, ActionListener al){
        ButtonGroup butGrp = new ButtonGroup();
        for (int i=0; i< elements.length;++i){
            JRadioButtonMenuItem rButton = new JRadioButtonMenuItem(elements[i], false);
            rButton.addActionListener(al);
            rButton.setActionCommand(""+i);
            if (selected==i)
                rButton.setSelected(true);
            butGrp.add(rButton);
            menu.add(rButton);
        }
    }


/*
 * ActionListeners para os vários menus do jogo
 */

    private class exitAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            myUI.exit();
        }
    }
    private class newGameAction implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            myUI.newGame();
            //System.out.println(myUI.getGameEngine().getBoard().toStringDebug());
        }
    }

    private class gameTypeAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());
            myUI.getGameEngine().setNewGameType(Integer.parseInt(e.getActionCommand()));
        }
    }
    private class blockShapeAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());
            myUI.setBlockShape(Integer.parseInt(e.getActionCommand()));
        }
    }
    private class layoutAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());
            myUI.setActiveLayout(Integer.parseInt(e.getActionCommand()));
        }
    }
    private class blockTypeAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());

            /*TODO*/

        }
    }
    private class undoMoveAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());
            myUI.undoMove();
        }
    }
    private class showHighScoresAction implements ActionListener{
        public void actionPerformed(ActionEvent e) {
            System.out.println(e.getActionCommand());
            myUI.showHighScores();
        }
    }
}
