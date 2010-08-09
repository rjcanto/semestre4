package SameGame.Game.model;

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
    public WBlock(){
        super(3, Color.BLACK);
        boolean r[][] = {{false,true,false},{false,false,false},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    public WBlock(int type){
        super(type, Color.BLACK);
        boolean r[][] = {{false,true,false},{false,false,false},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }

    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
}


