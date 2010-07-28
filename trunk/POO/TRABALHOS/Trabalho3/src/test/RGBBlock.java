package test;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */

public class RGBBlock extends Block {
    private static Color[] rgbColor = {Color.RED,Color.GREEN,Color.BLUE};
    public RGBBlock(){
        super(0, rgbColor[(new Random().nextInt(rgbColor.length))]);
    }
}
