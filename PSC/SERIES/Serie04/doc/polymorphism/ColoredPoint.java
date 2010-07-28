/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 */

public class ColoredPoint extends Point {
	protected RGB color;

	public ColoredPoint(String name) { this(0, 0, RGB.BLACK, name); }
	public ColoredPoint(int px, int py, RGB pcolor, String pname) {
		super(px, py, pname);
		color = pcolor.clone();
	}

	public RGB  getColor()           { return color.clone(); }
	public void setColor(RGB pcolor) { color = pcolor.clone(); }

	public void print() {
		System.out.println("{ name = \"" + name + "\"; x = " + x + "; y = " + y + "; color = " + color + " }");
	}
}
