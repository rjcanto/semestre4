package SameGame.Game.model;

import java.awt.Color;
import java.util.LinkedList;

/**
 *
 * @author Nuno
 */
public class BBlock extends Block{
    public BBlock(Board b, int x, int y){
        super(3, Color.BLACK, b);
        super.setCoord(x, y);
    }

    public LinkedList<Block> selectGroup(LinkedList<Block> list){
        return selectNeighbors(list, this.getRow());
    }

    private LinkedList<Block> selectNeighbors(LinkedList<Block> list, int row){
        for (int i=0; i<super.getBoard().getWidth();++i){
            super.getBoard().getBlock(row, i).select();
            list.add(super.getBoard().getBlock(row, i));
        }
        return list;
    }

}
