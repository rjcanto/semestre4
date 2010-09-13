/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.gui;


import SameGame.Game.gui.Game_Interfaces.GameShape_I;
import SameGame.Game.model.Block;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.event.MouseEvent;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JPanel;
import javax.swing.event.MouseInputListener;


public class GamePanel extends JPanel implements MouseInputListener {
    private SameGameUI_I myUI;
    private GameShape_I[][] board;
    private int BOARD_H = 10;
    private int BOARD_W = 10;
    private int width;
    private int height;

    private String[] blockShapes;
    private int activeShape;
    private int nextActiveShape;

    public GamePanel(SameGameUI_I ui){
        this.myUI = ui;
        setLayout(new GridLayout(BOARD_H,BOARD_W));
        setOpaque(true);
        setName("Game Panel");
        myUI.setGamePanel(this);
        board=new GameShape_I[BOARD_H][BOARD_W];
        for (int line =0;line<BOARD_H;++line){
            for(int col=0;col<BOARD_W;++col){
                getBoardInfo(line, col);
            }
        }
        getShapeSize();
        addMouseListener(this);
    }

    private void getShapeSize(){
        try{
            GameShape_I shape = (GameShape_I) Class.forName("SameGame.Game.gui.BlockShapes."
                +myUI.getBlockShapeNames()[myUI.getActiveBlockShape()]).
                getDeclaredConstructor(Color.class, int.class, int.class).
                newInstance(Color.white, 0, 0);
                width = shape.getWidth();
                height = shape.getHeight();
        } catch(Exception ex){
            Logger.getLogger(GamePanel.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            width=height=50;
        }
    }

    @Override
    public void paint (Graphics g) {
        super.paint(g);
        if (myUI.getGameEngine().getRemainingBlocks()==0)
            return;
        Graphics2D g2 = (Graphics2D)g;
        for (int line =0;line<BOARD_H;++line){
            for(int col=0;col<BOARD_W;++col){
                getBoardInfo(line, col);
                if( board[line][col] != null){
                    board[line][col].paintShape(g2);
                }
            }
        }
    }

    private void getBoardInfo(int line, int col){
        Block b = myUI.getGameEngine().getBlock(line, col);
        if (b==null){
            board[line][col]=null;
        }else{
        try{
            board[line][col] = (GameShape_I) Class.forName("SameGame.Game.gui.BlockShapes."
                +myUI.getBlockShapeNames()[myUI.getActiveBlockShape()]).
                getDeclaredConstructor(Color.class, int.class, int.class).
                newInstance(b.getColor(), line, col);
            if (b.isSelected())
                board[line][col].select();
        } catch(Exception ex){
            Logger.getLogger(GamePanel.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println(ex.getMessage());
            myUI.exit();
        }
        }
    }

    public void mouseClicked(MouseEvent e) {
        if(e.getX() > 0 && e.getY()> 0 && e.getX() < 500 && e.getY()<500  ){
            //System.out.println(e.getX()+":"+e.getY());
            int col = (e.getX()/width);
            int line = (e.getY()/height);
//            System.out.println(line+":"+col);
             
            if (board[line][col]!=null)
                myUI.clickedBlock(line, col);
        }
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mouseDragged(MouseEvent e) {}
    public void mouseMoved(MouseEvent e) {}
}
