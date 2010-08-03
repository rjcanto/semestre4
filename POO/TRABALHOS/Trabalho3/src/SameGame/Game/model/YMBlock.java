package SameGame.Game.model;

import java.awt.Color;
import java.util.Random;

/**
 *
 * @author Nuno
 */
public class YMBlock extends Block{
    private static Color[] ymColor = {Color.YELLOW,Color.MAGENTA};
    public YMBlock(Board b){
        super(1, ymColor[(new Random().nextInt(ymColor.length))], b);
    }
}
