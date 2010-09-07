package SameGame.Game.model;

/**
 *
 * @author 
 */
public class BlockSelectionRule implements BlockRule_I{
    private boolean rule[][];

    public BlockSelectionRule(boolean rule[][]){
        this.rule = new boolean[rule.length][rule[0].length];
        for (int line=0;line<rule.length;++line)
            for (int col=0;col<rule[0].length;++col)
               this.rule[line][col]=rule[line][col];
    }

    public boolean[][] getSelectionRule() {
        return this.rule;
    }

}
