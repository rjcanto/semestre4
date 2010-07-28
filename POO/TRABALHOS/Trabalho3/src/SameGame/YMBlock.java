package SameGame;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */
public class YMBlock extends Block{
    public YMBlock(){
        super(1, computeColor());
    }
    private static Color computeColor() {
       int r = new Random().nextInt(2);
       switch (r){
           case 0:  return Color.YELLOW;
           default:  return Color.MAGENTA;
       }
    }
}
