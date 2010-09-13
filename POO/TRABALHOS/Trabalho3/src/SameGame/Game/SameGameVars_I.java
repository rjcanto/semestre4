/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */

package SameGame.Game;


public interface SameGameVars_I {
    public final String SAVE_PATH ="src/Samegame/saved/";
    public final String SAVEGAME_FILENAME ="savegame.dat";
    public final String HIGHSCORES_FILENAME ="highscores.dat";
    public final String GAME_OPTIONS_FILENAME ="options.dat";

    public final String BLOCKS_PACKAGE="build/classes/Samegame/game/model/blocks";
    public final String GAMETYPE_PACKAGE="build/classes/Samegame/game/gameType";

    public final String FIELD_DELIMITER=";";

    /*File Error Codes*/
    public final int ERROR_HIGHSCORES = 1;
    public final int ERROR_SAVEGAME = 2;
    public final int ERROR_OPTIONS = 4;

    public final int ROTATE_LIMIT = 3;
    
}
