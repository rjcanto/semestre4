package SameGame.Game.model;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */
public class RGBBlock extends Block{
    private static Color[] rgbColor = {Color.RED,Color.GREEN,Color.BLUE};
    public RGBBlock(Board b){
        super(0, rgbColor[(new Random().nextInt(rgbColor.length))], b);
    }
}
