/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.model;

/**
 *
 * @author masterzdran
 */
public class Score {
    private int _gameType;
    private int _score;
    private String _name;

    public Score(String name, int score, int gameType) {
        _gameType   = gameType;
        _score      = score;
        _name       = name;
    }
    public int getScore(){return _score;}
    public String getName(){return _name;}
    public int getGameType(){return _gameType;}
    public void setScore(int score){_score= score;}
    public void setGameType(int position){_gameType = position;}
    public void setName(String name){_name = name;}


}
