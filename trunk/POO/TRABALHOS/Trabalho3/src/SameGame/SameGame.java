/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame;

import SameGame.Game.model.*;
import java.awt.Color;
import java.io.*;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author Nuno
 */
public class SameGame implements GameModelVars_I{

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

        Block block;

        //Class c = Class.forName("Page");
        String[] blockNames = {"RGBBlock"};

        Board b = new Board(4,4,blockNames);

//        for (int i=0; i<b.getHeight();++i)
//            for (int j=0; j<b.getWidth();++j)
//                b.addBlock(new RGBBlock(), i, j);

        b.addBlock(new WBlock(), 2, 0);

        b.addBlock(new BBlock(), 1, 2);
        System.out.println(b.toString());
        //list = b.getBlock(2, 1).selectGroup(list);
        //list = b.getBlock(0, 2).selectGroup(list);

        b.select(2,0);
        System.out.println(b.toString());
        b.unselect();
        System.out.println(b.toString());

        b.select(1,2);
        System.out.println(b.toString());
        b.unselect(1,1);
        System.out.println(b.toString());

        b.select(0,0);
        System.out.println(b.toString());
        b.removeSelected();
        System.out.println(b.toString());
        
        b.rotate(false);
        System.out.println(b.toString());
        b.rotate(false);
        System.out.println(b.toString());
        b.rotate(true);
        System.out.println(b.toString());
        b.rotate(true);
        System.out.println(b.toString());

        System.out.println(b.toString());
        b.shiftDown();
        System.out.println(b.toString());
        b.rotate(false);
        System.out.println("left");
        System.out.println(b.toString());
        b.shiftDown();
        System.out.println(b.toString());
        b.rotate(true);
        System.out.println("right");
        System.out.println(b.toString());
        b.rotate(true);
        System.out.println("right");
        System.out.println(b.toString());




        

    }

}
