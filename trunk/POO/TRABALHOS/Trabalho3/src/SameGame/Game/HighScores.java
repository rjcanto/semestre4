/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package SameGame.Game;

import java.util.Iterator;
import java.util.LinkedList;

/**
 *
 * @author Nuno
 */
public class HighScores{

    private LinkedList<Score> highScores;
    private int maxElements;
    private class Score{
        private String name;
        private int score;

        protected Score(){
            this.name="<empty>";
            this.score=0;
        }
        protected Score(String name, int score){
            this.name=name;
            this.score=score;
        }
        public String getName() {return name;}
        public void setName(String name) {this.name = name;}
        public int getScore() {return score;}
        public void setScore(int score) {this.score = score;}
    }

    public HighScores(){
        highScores = new LinkedList<Score>();
        maxElements=10;
        init();
    }
    public HighScores(int max){
        highScores = new LinkedList<Score>();
        maxElements=max;
        init();
    }

    public int getMaxElements() {return maxElements;}
    public void setMaxElements(int maxElements) {this.maxElements = maxElements;}
    public int getSize() {return highScores.size();}

    private void init(){
        for (int i=0; i<maxElements;++i)
            highScores.add(new Score());
    }

    public void reset(){
        highScores = new LinkedList<HighScores.Score>();
        init();
    }

    public boolean isHighScore(int score){
        if (highScores.get(maxElements-1).getScore()<score)
            return true;
        return false;
    }

    public boolean add(String name, int score){
        int i=0;
        if (isHighScore(score)){
            Iterator<Score> it = highScores.iterator();
            while (it.hasNext()){
                if (it.next().getScore()<score){
                    highScores.add(i, new Score(name, score));
                    highScores.removeLast();
                    return true;
                }
                ++i;
            }
        }
        return false;
    }

    public String[] get(){
        int i=0;
        String[] res= new String[highScores.size()];
        Iterator<Score> it = highScores.iterator();
        while (it.hasNext()){
            Score aux = it.next();
            res[i++]= aux.getName() + " - " +aux.getScore();
        }
        return res;
    }

    @Override
    public String toString(){
        String res= "";
        Iterator<Score> it = highScores.iterator();
        while (it.hasNext()){
            Score aux = it.next();
            res+= aux.getName() + ";" +aux.getScore()+";\n";
        }
        return res;
    }



}
