package test.game.model;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */

public class RGBBlock extends Block {
    private static Color[] rgbColor = {Color.RED,Color.GREEN,Color.BLUE};
    private BlockSelectionRule rule;
    /**
     * Vermelho, Verde e Azul – bloco que para ser removido precisa de pelo
     * menos um bloco adjacente (na horizontal e na vertical) a ele do mesmo
     * tipo; 
     */
    public RGBBlock(){
        super(0, rgbColor[(new Random().nextInt(rgbColor.length))]);
        boolean r[][] = {{false,true,false},{true,false,true},{false,true,false}};
        rule = new BlockSelectionRule(r);
    }
    @Override
    public boolean[][] getSelectionRule(){return this.rule.getSelectionRule();}
}
