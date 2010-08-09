package SameGame.Game.model;

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
    public BBlock(){
        super(3, Color.BLACK);
        boolean r[][] = {{false,false,false},{true,false,true},{false,false,false}};
        rule = new BlockSelectionRule(r);
    }
    public BBlock(int type){
        super(type, Color.BLACK);
        boolean r[][] = {{false,false,false},{true,false,true},{false,false,false}};
        rule = new BlockSelectionRule(r);
    }

    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
}


