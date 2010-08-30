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

    private Board myBoard;

    public GravRules(SameGameEngine eng){
        super(eng);
        myBoard = eng.getBoard();
        resetScores();
    }

    public void clickedBlock(int r, int c) {
        if(myBoard.isSelected(r, c)){
            myBoard.saveState(getGameEngine().getScore());
            myBoard.removeSelected();
            myBoard.shiftDown();
            myBoard.removeEmptyColumns();
            updateScore();
        }else{
            myBoard.unselect();
            myBoard.select(r, c);
            getGameEngine().setParcialScore(myBoard.getNumberSelectedBlocks());
        }
    }
    public void rotateBoard(boolean right){
        myBoard.rotate(right);
        myBoard.shiftDown();
        myBoard.removeEmptyColumns();
    }


}
