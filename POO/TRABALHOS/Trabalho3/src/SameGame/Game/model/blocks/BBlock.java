package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import SameGame.Game.model.BlockSelectionRule;
import java.awt.Color;

/**
 *
 * @author Nuno
 */
public class BBlock extends Block{
    private BlockSelectionRule rule;
    /**
     *Preto – bloco que permite eliminar uma linha independentemente da cor dos blocos nessa linha;
     */
    public BBlock(int type){
        super(type, Color.BLACK);
        boolean r[][] = {{false,false,false},{true,false,true},{false,false,false}};
        rule = new BlockSelectionRule(r);
    }
    public BBlock(int type, Color c){
        super(type, c);
        boolean r[][] = {{false,false,false},{true,false,true},{false,false,false}};
        rule = new BlockSelectionRule(r);
    }
    public BBlock(int type, int colorID){
        super(type, Color.BLACK);
        boolean r[][] = {{false,false,false},{true,false,true},{false,false,false}};
        rule = new BlockSelectionRule(r);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
    @Override
    public String toString() {
        return ""+this.getClass().getSimpleName()+";"+0+";";
    }
    public String toStringDebug() {
        return " B "+"-"+0+"-";
    }
}


