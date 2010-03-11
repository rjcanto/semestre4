import java.util.HashMap;
import java.util.Map;

public class tests {
	interface cmdLnArgMethod{ void generalMethod();	}
	
	interface argsMethods{
		public final Map<String, cmdLnArgMethod> argsMap= 
			new HashMap<String, cmdLnArgMethod>(){
				{
					put("", new cmdLnArgMethod(){public void generalMethod(){none();}});
					put("-create", new cmdLnArgMethod(){public void generalMethod(){create();}});
					put("-load", new cmdLnArgMethod(){public void generalMethod(){load();}});
					put("-gen_ddl", new cmdLnArgMethod(){public void generalMethod(){gen_ddl();}});
					put("-gen_dml", new cmdLnArgMethod(){public void generalMethod(){gen_dml();}});
					put("-quc", new cmdLnArgMethod(){public void generalMethod(){quc();}});
					put("-quc_owner", new cmdLnArgMethod(){public void generalMethod(){quc_owner();}});
					put("-qowners", new cmdLnArgMethod(){public void generalMethod(){qowners();}});
					put("-qnot_owner", new cmdLnArgMethod(){public void generalMethod(){qnot_owner();}});
				}
				
			};
	}

	public static void none(){System.out.println("[Calling]: NONE");};
	public static void create(){System.out.println("[Calling]: etapa0 -create [-force]");};
	public static void load(){System.out.println("[Calling]: etapa0 -load <input_file_path>");};
	public static void gen_ddl(){System.out.println("[Calling]: etapa0 -gen_ddl <output_file_path>");};
	public static void gen_dml(){System.out.println("[Calling]: etapa0 -gen_dml <output_file_path>");};
	public static void quc(){System.out.println("[Calling]: etapa0 -quc [elective | required]");};
	public static void quc_owner(){System.out.println("[Calling]: etapa0 -quc_owner <owner_number>");};
	public static void qowners(){System.out.println("[Calling]: etapa0 -qowners");};
	public static void qnot_owner(){System.out.println("[Calling]: etapa0 -qnot_owner");};

	/**
	 * MAIN:
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] ping = { "-create", "-load", "-gen_ddl", "-gen_dml", "-quc", "-quc_owner", "-qowners", "-qnot_owner" };
		for (int i = 0; i < ping.length; ++i)
			argsMethods.argsMap.get(ping[i]).generalMethod();
		System.out.println(argsMethods.argsMap.size());
	}

	
}



