package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import SameGame.Game.model.BlockSelectionRule;
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
    public YMBlock(int type){
        super(type, ymColor[(new Random().nextInt(ymColor.length))]);
        boolean r[][] = {{true,true,true},{true,true,true},{true,true,true}};
        rule = new BlockSelectionRule(r);
    }
    public YMBlock(int type, Color c){
        super(type, c);
        boolean r[][] = {{true,true,true},{true,true,true},{true,true,true}};
        rule = new BlockSelectionRule(r);
    }
    public YMBlock(int type, int colorID){
        super(type, ymColor[colorID]);
        boolean r[][] = {{true,true,true},{true,true,true},{true,true,true}};
        rule = new BlockSelectionRule(r);
    }


    @Override
     public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}

    @Override
    public String toString() {
        return ""+this.getClass().getSimpleName()+";"+getColorID()+";";
    }
    private int getColorID() {
        int i=0;
        while(!ymColor[i].equals(super.getColor()))
            ++i;
        return i;
    }

    public String toStringDebug() {
        return "YM "+"-"+getColorID()+"-";
    }

}
