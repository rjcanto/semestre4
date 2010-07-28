/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 */

public final class RGB implements Cloneable {
	private byte r;
	private byte g;
	private byte b;

	public RGB()      { this(0); }
	public RGB(int i) { this(i, i, i); }
	public RGB(int r, int g, int b)
	{
		this.r = (byte)r;
		this.g = (byte)g;
		this.b = (byte)b;
	}

	public int getR() { return r >= 0 ? r : (256 + r); }
	public int getG() { return r >= 0 ? r : (256 + r); }
	public int getB() { return r >= 0 ? r : (256 + r); }

	public boolean isGray() { return r == g && g == b;  }

	public void setR(int r) { this.r = (byte)r; }
	public void setG(int g) { this.g = (byte)g; }
	public void setB(int b) { this.b = (byte)b; }

	public RGB clone() { try { return (RGB)super.clone(); } catch(CloneNotSupportedException cnse) { throw new Error(cnse); } }
	public String toString() { return String.format("RGB:%02X%02X%02X", r, g, b); }

	public static final RGB BLACK = new RGB();
	public static final RGB DGRAY = new RGB(84);
	public static final RGB LGRAY = new RGB(170);
	public static final RGB WHITE = new RGB(255);
	public static final RGB RED   = new RGB(255, 0, 0);
	public static final RGB GREEN = new RGB(0, 255, 0);
	public static final RGB BLUE  = new RGB(0, 0, 255);
}
