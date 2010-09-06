package test.game.model;

import java.awt.Color;

/**
 *
 * @author Nuno
 */
public class WBlock extends Block{
    private BlockSelectionRule rule;
    /**
     * Branco  –  bloco que permite eliminar uma coluna independentemente da cor
     * dos blocos nessa coluna.
     */
    public WBlock(){
        super(2,Color.WHITE);
        boolean r[][] = {{false,true,false},{false,true,false},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
}
