/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.model.blocks;

import SameGame.Game.model.Block;
import java.awt.Color;


public class WBlock extends Block{
    private static Color[] myColors = {Color.WHITE};
    private final boolean rule[][] = {{false,true,false},{false,false,false},{false,true,false}};
    /**
     *Branco – bloco que permite eliminar uma coluna independentemente da cor dos blocos nessa linha;
     */
    public WBlock(int type){
        this(type, myColors[0]);
    }
    public WBlock(int type, int colorID){
        this(type, myColors[colorID]);
    }
    public WBlock(int type, Color c){
        super(type, c);
    }
    @Override
     public boolean[][] getSelectionRule(){return this.rule;}

    @Override
    public String toString() {
        return ""+this.getClass().getSimpleName()+";"+0+";";
    }

    public String toStringDebug() {
        return " W "+"-"+0+"-";
    }
}


