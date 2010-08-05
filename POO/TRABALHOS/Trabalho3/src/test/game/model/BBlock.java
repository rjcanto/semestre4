package test.game.model;

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
        boolean r[][] = {{false,false,false},{true,true,true},{false,false,false}};
        rule = new BlockSelectionRule(r);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
}
