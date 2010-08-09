package SameGame.Game.model;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */
public class YMBlock extends Block{
    private static Color[] ymColor = {Color.YELLOW,Color.MAGENTA};
    private BlockSelectionRule rule;
    /**
     * Amarelo e Magenta – bloco que para ser removido precisa de pelo menos um
     * bloco adjacente a ele, incluindo diagonais, que seja do mesmo tipo;
     */
    public YMBlock(){
        super(1, ymColor[(new Random().nextInt(ymColor.length))]);
        boolean r[][] = {{true,true,true},{true,true,true},{true,true,true}};
        rule = new BlockSelectionRule(r);
    }
    public YMBlock(int type){
        super(1, ymColor[(new Random().nextInt(ymColor.length))]);
        boolean r[][] = {{true,true,true},{true,true,true},{true,true,true}};
        rule = new BlockSelectionRule(r);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
}
