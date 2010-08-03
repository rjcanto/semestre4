/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame;

import SameGame.Game.model.*;
import java.util.Iterator;
import java.util.LinkedList;


/**
 *
 * @author Nuno
 */
public class SameGame {

    /**
     * @param args the command line arguments
     */
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
    
//        SameGameGUI sg = new SameGameGUI(5,5);

        Board b = new Board(4,4);

        for (int i=0; i<b.getHeight();++i)
            for (int j=0; j<b.getWidth();++j)
                b.addBlock(new BBlock(b,i,j), i, j);

        b.addBlock(new WBlock(b,0,2));
        LinkedList<Block> list = new LinkedList<Block>();
        list = b.getBlock(2, 1).selectGroup(list);
        list = b.getBlock(0, 2).selectGroup(list);

        System.out.println(b.toString());

        Iterator it = list.iterator();

        while (it.hasNext()){
            Block b1 = (Block) it.next();
            b.removeBlock(b1);
        }

        System.out.println(b.toString());
        b.shiftDown();
        System.out.println(b.toString());
        b.rotateLeft();
        System.out.println("left");
        System.out.println(b.toString());
        b.shiftDown();
        System.out.println(b.toString());
        b.rotateRight();
        System.out.println("right");
        System.out.println(b.toString());
        b.rotateRight();
        System.out.println("right");
        System.out.println(b.toString());




        

    }

}
