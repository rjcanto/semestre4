/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.gameType;
import SameGame.Game.SameGameEngine;
import SameGame.Game.SameGameRules;
import SameGame.Game.model.Board;

public class MegaGravRules extends SameGameRules {

    public MegaGravRules(SameGameEngine eng){
        super(eng, true);
    }

    @Override
    public void clickedBlock(int r, int c) {
        Board myBoard = getGameEngine().getBoard();
        if(myBoard.isSelected(r, c)){
            myBoard.saveState(getGameEngine().getScore(), getGameEngine().getRotateLimit());
            myBoard.removeSelected();
            myBoard.shiftDown();
            if (myBoard.removeEmptyColumns())
                myBoard.fillEmptyColumns(false);
            updateScore();
            getGameEngine().verifyEnd();
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
