package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import java.awt.Color;

/**
 *
 * @author Nuno
 */
public class BBlock extends Block{
    private static Color[] myColors = {Color.BLACK};
    private boolean rule[][] = {{false,false,false},{true,false,true},{false,false,false}};
    /**
     *Preto – bloco que permite eliminar uma linha independentemente da cor dos blocos nessa linha;
     */
    public BBlock(int type){
        this(type, myColors[0]);
    }
    public BBlock(int type, int colorID){
        this(type, myColors[colorID]);
    }
    public BBlock(int type, Color c){
        super(type, c);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule;}
    @Override
    public String toString() {
        return ""+this.getClass().getSimpleName()+";"+0+";";
    }
    public String toStringDebug() {
        return " B "+"-"+0+"-";
    }
}


