package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import SameGame.Game.model.BlockSelectionRule;
import java.awt.Color;
import java.util.LinkedList;

/**
 *
 * @author Nuno
 */
public class WBlock extends Block{
    private BlockSelectionRule rule;
    /**
     *Branco – bloco que permite eliminar uma coluna independentemente da cor dos blocos nessa linha;
     */
    public WBlock(int type){
        super(type, Color.WHITE);
        boolean r[][] = {{false,true,false},{false,false,false},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    public WBlock(int type, Color c){
        super(type, c);
        boolean r[][] = {{false,true,false},{false,false,false},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    public WBlock(int type, int colorID){
        super(type, Color.WHITE);
        boolean r[][] = {{false,true,false},{false,false,false},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }

    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}

    @Override
    public String toString() {
        return ""+this.getClass().getSimpleName()+";"+0+";";
    }

    public String toStringDebug() {
        return " W "+"-"+0+"-";
    }
}


