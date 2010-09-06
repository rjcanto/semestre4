/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game;

/**
 *
 * @author Nuno
 */
public interface SameGameVars_I {

    public final String SAVE_PATH ="src/SameGame/Saved";
    public final String SAVEGAME_FILENAME ="savegame.dat";
    public final String HIGHSCORES_FILENAME ="highscores.dat";
    public final String GAME_OPTIONS_FILENAME ="options.dat";
    public final String BLOCKS_PACKAGE="build/classes/SameGame/Game/model/blocks";
    public final String GAMETYPE_PACKAGE="build/classes/SameGame/Game/gameType";

    public final String FILE_DELIMITER=";";

    /*File Error Codes*/
    public final int ERROR_HIGHSCORES = 1;
    public final int ERROR_OPTIONS = 2;
    public final int ERROR_SAVEGAME = 4;
    
}