import java.util.Scanner;

public final class Minesweeper {
  public static Board board;
  public static boolean exit;
  
  public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	board = new Board();
	Command.load("Commands.cfg");
	while (!exit) {
		board.print();
		System.out.print("> ");
		Command.execute(in.nextLine());
	}
  }
}
