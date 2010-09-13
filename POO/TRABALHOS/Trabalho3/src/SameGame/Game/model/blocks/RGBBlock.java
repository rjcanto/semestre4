/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import java.awt.Color;
import java.util.Random;


public class RGBBlock extends Block{
    private static Color[] myColors = {Color.RED,Color.GREEN,Color.BLUE};
    private final boolean rule[][] = {{false,true,false},{true,true,true},{false,true,false}}; // Alteração
    /**
     * Vermelho, Verde e Azul – bloco que para ser removido precisa de pelo
     * menos um bloco adjacente (na horizontal e na vertical) a ele do mesmo
     * tipo;
     */
    public RGBBlock(int type){
       this(type, myColors[(new Random().nextInt(myColors.length))]);
    }
    public RGBBlock(int type, int colorID){
        this(type, myColors[colorID]);
    }
    public RGBBlock(int type, Color c){
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
        return "RGB"+"-"+getColorID()+"-";
    }
}
