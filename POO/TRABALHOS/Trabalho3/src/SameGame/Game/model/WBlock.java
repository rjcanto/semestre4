package SameGame.Game.model;

import java.awt.Color;
import java.util.LinkedList;

/**
 *
 * @author Nuno
 */
public class WBlock extends Block{
    public WBlock(Board b, int r, int c){
        super(2,Color.WHITE, b);
        super.setCoord(r, c);
    }
    
    public LinkedList<Block> selectGroup(LinkedList<Block> list){
        return selectNeighbors(list, this.getColumn());
    }

    private LinkedList<Block> selectNeighbors(LinkedList<Block> list, int col){
        for (int i=0; i<super.getBoard().getWidth();++i){
            super.getBoard().getBlock(i, col).select();
            list.add(super.getBoard().getBlock(i, col));
        }
        return list;
    }
}
