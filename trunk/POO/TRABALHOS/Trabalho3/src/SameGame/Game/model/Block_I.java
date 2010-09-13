/*
 * ISEL - POO
 * 3º trabalho Semestre Verão 2009/2010
 * 33595 - Nuno Sousa
 */
package SameGame.Game.model;

import java.awt.Color;


public interface Block_I {
    public void setColor(Color c);
    public Color getColor();
    public boolean isSelected();
    public void unselect();
    public void select();
    @Override
    public String toString();
}
