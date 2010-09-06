/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test.game.model;

import java.awt.Color;

/**
 *
 * @author nac
 */
public interface Block_I {
    public void setColor(Color c);
    public Color getColor();
    public boolean isSelected();
    public void unselect();
    public void select();
}
