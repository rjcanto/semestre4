/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import java.awt.Color;
import java.util.Random;


public class YMBlock extends Block{
    private static Color[] myColors = {Color.YELLOW,Color.MAGENTA};
    private final boolean rule[][] = {{true,true,true},{true,true,true},{true,true,true}};
    /**
     * Amarelo e Magenta – bloco que para ser removido precisa de pelo menos um
     * bloco adjacente a ele, incluindo diagonais, que seja do mesmo tipo;
     */
    public YMBlock(int type){
        this(type, myColors[(new Random().nextInt(myColors.length))]);
    }
    public YMBlock(int type, int colorID){
        this(type, myColors[colorID]);
    }
    public YMBlock(int type, Color c){
        super(type, c);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule;}

    @Override
    public String toString() {
        return ""+this.getClass().getSimpleName()+";"+getColorID()+";";
    }
    private int getColorID() {
        int i=0;
        while(!myColors[i].equals(super.getColor()))
            ++i;
        return i;
    }

    public String toStringDebug() {
        return "YM "+"-"+getColorID()+"-";
    }

}
