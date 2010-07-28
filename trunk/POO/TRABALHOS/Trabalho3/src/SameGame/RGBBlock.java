package SameGame;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */
public class RGBBlock extends Block{
    public RGBBlock(){
        super(0, computeColor());
    }
    private static Color computeColor() {
       int r = new Random().nextInt(3);
       switch (r){
           case 0:  return Color.RED;
           case 1:  return Color.GREEN;
           default: return Color.BLUE;
       }
    }
}
