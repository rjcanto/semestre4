package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import SameGame.Game.model.BlockSelectionRule;
import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */
public class RGBBlock extends Block{
    private static Color[] rgbColor = {Color.RED,Color.GREEN,Color.BLUE};
    private BlockSelectionRule rule;
    /**
     * Vermelho, Verde e Azul – bloco que para ser removido precisa de pelo
     * menos um bloco adjacente (na horizontal e na vertical) a ele do mesmo
     * tipo;
     */
    public RGBBlock(int type){
        super(type, rgbColor[(new Random().nextInt(rgbColor.length))]);
        boolean r[][] = {{false,true,false},{true,true,true},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    public RGBBlock(int type, Color c){
        super(type, c);
        boolean r[][] = {{false,true,false},{true,true,true},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    public RGBBlock(int type, int colorID){
        super(type, rgbColor[colorID]);
        boolean r[][] = {{false,true,false},{true,true,true},{false,true,false}};
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
        while(!rgbColor[i].equals(super.getColor()))
            ++i;
        return i;
    }
    public String toStringDebug() {
        return "RGB"+"-"+getColorID()+"-";
    }
}
