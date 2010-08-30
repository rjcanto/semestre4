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
public class MegaShifterRules extends SameGameRules {

    private Board myBoard;
    
    public MegaShifterRules(SameGameEngine eng){
        super(eng);
        myBoard = eng.getBoard();
        resetScores();
    }

    @Override
    public void selectBlock(int r, int c) {
        if(myBoard.isSelected(r, c)){
            myBoard.saveState(getGameEngine().getScore());
            myBoard.removeSelected();
            myBoard.shiftDown();
            myBoard.shiftLeft();
            myBoard.fillEmptyColumns(true);
            updateScore();
        }else{
            myBoard.unselect();
            myBoard.select(r, c);
            getGameEngine().setParcialScore(myBoard.getSelectedBlocks());
        }
    }
    public void rotateBoard(boolean right){
        myBoard.rotate(right);
        myBoard.shiftDown();
        myBoard.shiftLeft();
        myBoard.fillEmptyColumns(true);
    }

    public void unselectBlock(int r, int c) {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}