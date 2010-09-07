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
public class GravRules extends SameGameRules {

    public GravRules(SameGameEngine eng){
        super(eng, false);
        resetScores();
    }

    public void clickedBlock(int r, int c) {
        Board myBoard = getGameEngine().getBoard();
        if(myBoard.isSelected(r, c)){
            myBoard.saveState(getGameEngine().getScore());
            myBoard.removeSelected();
            myBoard.shiftDown();
            myBoard.removeEmptyColumns();
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
        myBoard.removeEmptyColumns();
    }
}
