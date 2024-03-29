/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.gui;
import SameGame.Game.FileAccess;
import SameGame.Game.model.HighScores;
import SameGame.Game.SameGameEngine;
import SameGame.Game.SameGameEngineAbstract;
import java.awt.*;
import java.util.Observable;
import java.util.Observer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;


public class SameGameGUI extends Observable implements SameGameUI_I, GameGUIVars_I, Observer{

    private SameGameEngineAbstract engine;
    private JFrame gameFrame;
    private JMenuBar mainMenu;
    private InfoPanel infoPanel;
    private GamePanel gamePanel;
    private Layout_I layout;

    int width;
    int height;
    private String[] layouts;
    private int activeLayout;
    private String[] blockShapes;
    private int activeBlockShape;


    public SameGameGUI(int width, int height, SameGameEngine eng){
        this.width=width; this.height=height;
        this.engine = eng;
        this.engine.setUI(this);
        layouts = new FileAccess().getFileNames(LAYOUTS_PACKAGE);
        blockShapes = new FileAccess().getFileNames(BLOCKSHAPES_PACKAGE);
        getActiveOptions();
        createAndShowGUI(width, height);
    }
    private void createAndShowGUI(int width, int height) {
        Dimension screenSize    = Toolkit.getDefaultToolkit().getScreenSize();
        gameFrame               = new mainWindow(800,600, this);

        if (mainMenu==null)
            mainMenu = new mainMenu(this);

        gameFrame.setJMenuBar(mainMenu);
        gameFrame.getContentPane().add((JPanel)createLayout(activeLayout));
        gameFrame.setResizable(false);
        gameFrame.setLocation((screenSize.width - gameFrame.getWidth())/2, (screenSize.height - gameFrame.getHeight())/2);
        gameFrame.pack();
        gameFrame.setVisible(true);
        engine.addObserver(this);
    }

    public void setGameEngine(SameGameEngineAbstract c) {this.engine = c;}
    public SameGameEngineAbstract getGameEngine(){return engine;}
    public String[] getLayoutNames() {return this.layouts;}
    public int getActiveLayout() {return this.activeLayout;}
    public void setInfoPanel(InfoPanel i){this.infoPanel=i;}
    public void setGamePanel(GamePanel g){this.gamePanel=g;}
    public void setActiveLayout(String lname){
        for (int i=0; i<layouts.length;++i)
            if (layouts[i].equalsIgnoreCase(lname)){
                activeLayout=i;
                break;
            }
    }
    public void setActiveLayout(int i) {
        if (activeLayout==i) return;
        this.activeLayout = i;
        gameFrame.dispose();
        createAndShowGUI(width, height);
    }
    private Layout_I createLayout(int l) {
        boolean hadLayout = (layout==null)?false:true;
        try{
            layout = (Layout_I) Class.forName("SameGame.Game.gui.Layouts."+layouts[l]).
                    getDeclaredConstructor(SameGameUI_I.class).newInstance(this);
        } catch(Exception ex){
            Logger.getLogger(SameGameGUI.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            if(!hadLayout) System.exit(0);
        }
        return layout;
    }


    public String[] getBlockShapeNames() {return blockShapes;}
    public int getActiveBlockShape() {return activeBlockShape;}
    public void setBlockShape(int i) {
        activeBlockShape=i;
        gamePanel.validate();
        gamePanel.repaint();
    }

    public void rotate(boolean right){engine.rotateBoard(right);}
    public void undoMove(){engine.undoMove();}

    public void clickedBlock(int r, int c){
        engine.clickedBlock(r, c);
        //System.out.println(engine.getBoard().toStringDebug());
    }
    private void getActiveOptions() {
        String l = engine.getFile().getSavedLayoutName();
        activeLayout=0;
        for (int i=0; i< layouts.length;++i)
            if(layouts[i].equalsIgnoreCase(l)) {
                activeLayout = i;
                break;
            }
        String bs = engine.getFile().getSavedBlockShapeName();
        activeBlockShape=0;
        for (int i=0; i< blockShapes.length;++i)
            if(blockShapes[i].equalsIgnoreCase(bs)) {
                activeBlockShape = i;
                break;
            }
    }

    public void newGame(){
        engine.newGame(false);
    }
    public void exit() {engine.exit();}
    public void showHighScores() {
        HighScores[] hs= engine.getAllHighScores();
        for (int i=0;i<hs.length;++i)
            System.out.println(hs[i].toString());
    }
    public void showHighScores(HighScores hs) {
        System.out.println(hs.toString());
    }
    public String getHighScoreName() {
        return "Nuno";
    }
    public void update(Observable o, Object arg) {
        infoPanel.updateInfo();
        gamePanel.validate();
            gamePanel.repaint();
    }



}
