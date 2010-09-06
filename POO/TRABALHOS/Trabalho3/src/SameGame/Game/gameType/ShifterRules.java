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
public class ShifterRules extends SameGameRules {

    public ShifterRules(SameGameEngine eng){
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
            myBoard.shiftLeft();
            updateScore();
        }else{
            myBoard.unselect();
            myBoard.select(r, c);
            getGameEngine().setParcialScore(myBoard.getNumberSelectedBlocks());
        }
    }
    public void rotateBoard(boolean right){
        Board myBoard = getGameEngine().getBoard();
        myBoard.rotate(right);
        myBoard.shiftDown();
        myBoard.shiftLeft();
    }
}
