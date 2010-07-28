public class Avg implements Oper {
  private int count = 0;
  Sum sum = new Sum();
  
  public String name() 				{ return "Avg"; }
  public void insert(float val)  { count++; sum.insert(val); }
  public float result()				{ return sum.result()/count; }
  public void reset()			   { count=0; sum.reset(); }
}
