/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game.model;

/**
 *
 * @author Nuno
 */
public interface GameModelVars_I {

    public final int[] TOP_LEFT={-1,-1};
    public final int[] TOP ={-1,0};
    public final int[] TOP_RIGHT ={-1,+1};
    public final int[] LEFT ={0,-1};
    public final int[] CENTER ={0, 0};
    public final int[] RIGHT ={0,1};
    public final int[] BOTTOM_LEFT ={+1,-1};
    public final int[] BOTTOM ={+1,0};
    public final int[] BOTTOM_RIGHT ={+1,+1};
    public final int[][] ROW_OFFSET = {{-1,-1,-1},
                                       { 0, 0, 0},
                                       { 1, 1, 1}};
    public final int[][] COLUMN_OFFSET = {{-1, 0, 1},
                                       {-1, 0, 1},
                                       {-1, 0, 1}};
    public final Coordinates[][] OFFSET =
        {{new Coordinates(-1,-1), new Coordinates(-1,0), new Coordinates(-1, 1)},
         {new Coordinates( 0,-1), new Coordinates( 0,0), new Coordinates( 0, 1)},
         {new Coordinates( 1,-1), new Coordinates( 1,0), new Coordinates( 1, 1)}};

}
