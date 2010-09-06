/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.gameType;
import SameGame.Game.SameGameEngine;
import SameGame.Game.SameGameRules;
import SameGame.Game.model.Board;

/**
 *
 * @author Nuno
 */
public class MegaGravRules extends SameGameRules {

    public MegaGravRules(SameGameEngine eng){
        super(eng);
        resetScores();
    }

    @Override
    public void clickedBlock(int r, int c) {
        Board myBoard = getGameEngine().getBoard();
        if(myBoard.isSelected(r, c)){
            myBoard.saveState(getGameEngine().getScore());
            myBoard.removeSelected();
            myBoard.shiftDown();
            if (myBoard.removeEmptyColumns())
                myBoard.fillEmptyColumns(false);
            updateScore();
        }else{
            myBoard.unselect();
            myBoard.select(r, c);
            setParcialScore(myBoard.getNumberSelectedBlocks());
        }
    }
    public void rotateBoard(boolean right){
        Board myBoard = getGameEngine().getBoard();
        myBoard.rotate(right);
        myBoard.shiftDown();
        if (myBoard.removeEmptyColumns())
            myBoard.fillEmptyColumns(false);
    }
}
