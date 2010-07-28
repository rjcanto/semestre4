import java.util.*;

public class Opers {
  public static void main(String args[]) throws Exception {
    Scanner in = new Scanner(System.in);
    Oper[] op = new Oper[args.length];
    String line;
    for(int i=0; i<args.length ; ++i)
      op[i] = loadOper(args[i]);
    while ( (line = in.nextLine()).length()>0 )
      for(int i=0; i<args.length ; ++i)
        execOper(op[i],line);
  }
  
  public static Oper loadOper(String opName) throws Exception {
    Class c = Class.forName(opName);
    Object o = c.newInstance();
    return (Oper)o;
  }
  
  public static void execOper(Oper op, String line) {
    Scanner in = new Scanner(line);
    op.reset();
    while( in.hasNextFloat() ) {
      op.insert( in.nextFloat() );
    }
 	 System.out.println(op.name()+" = "+op.result());   
  }
}
