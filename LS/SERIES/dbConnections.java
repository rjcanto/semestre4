package jTests;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.sql.*;
import java.util.Properties;
import com.microsoft.sqlserver.jdbc.SQLServerDriver;
import net.sourceforge.jtds.jdbc.*;
public class dbConnections {

	private static final String HOST="10.0.0.112";
	private static final String PORT="3188";
	private static final String DATABASE="SI1";
	private static final String USERNAME="zdran";
	private static final String PASSWORD="masterzdran";
	private static final String LINUX_DRIVER="net.sourceforge.jtds.jdbc.Driver";
	private static final String LINUX_DB_URL="jdbc:jtds:sqlserver://"+HOST+":"+PORT;
	private static final String WINDOWS_DRIVER="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	private static final String WINDOWS_DB_URL="jdbc:sqlserver://"+HOST+":"+PORT;
	

	public static Connection getConnection() throws Exception {
		
		//Class.forName("net.sourceforge.jtds.jdbc.Driver");
		//String dbURL = "jdbc:jtds:sqlserver://"+HOST+":"+PORT+"/"+DATABASE;
		Class.forName((System.getProperty("os.name").compareToIgnoreCase("LINUX")== 0)?LINUX_DRIVER:WINDOWS_DRIVER);
		
	    String dbURL =(System.getProperty("os.name").compareToIgnoreCase("LINUX")== 0)?LINUX_DB_URL:WINDOWS_DB_URL;
	    Connection conn=null;

        try
        {
            
            conn = DriverManager.getConnection(dbURL, USERNAME, PASSWORD);
            System.out.println("connected");
            if (conn != null) {
                System.out.println();
                 System.out.println("Successfully connected");
                 System.out.println();
                 // Meta data
                 DatabaseMetaData meta = conn.getMetaData();
                 System.out.println("\nDriver Information");
                 System.out.println("Driver Name: "
                  + meta.getDriverName());
                 System.out.println("Driver Version: "
                  + meta.getDriverVersion());
                 System.out.println("\nDatabase Information ");
                 System.out.println("Database Name: "
                  + meta.getDatabaseProductName());
                 System.out.println("Database Version: "+
                 meta.getDatabaseProductVersion());
               }

            
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

	    return conn;
	  }
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//		Properties dbProp=new Properties();
//		dbProp.setProperty("host", "host.address");
//		dbProp.setProperty("port", "port.address");
//		dbProp.setProperty("username", "username");
//		dbProp.setProperty("password", "password");
//		try {
//			FileOutputStream out = new FileOutputStream(DB_PROPERTIES_FILE);
//			dbProp.store(out, "Teste");
//
//		} catch (FileNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		
//		}

		
		InetAddress addr=null;
		try { 
			addr = InetAddress.getLocalHost(); 

		} catch (UnknownHostException e) { } 
		
		System.out.println("IPAddr:"+addr.getHostAddress()+"\nHostname:"+addr.getHostName());
		try {
			System.out.print(System.getProperty("os.name")+"\n"+getConnection());
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}



}
