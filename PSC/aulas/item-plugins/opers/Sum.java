public class Sum implements Oper {
  private float total = 0;
  
  public String name() 		{ return "Sum"; }
  public void insert(float val)   { total+=val; }
  public float result()				{ return total; }
  public void reset()					{ total=0; }
}
