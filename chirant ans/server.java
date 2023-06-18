import java.io.*;
import java.util.*;
import java.net.*;

public class server{
	public static void main(String[] args) throws IOException{
		ServerSocket ss = new ServerSocket(8000);
		Socket c = ss.accept();

		System.out.println("Connection established!");

		DataInputStream din = new DataInputStream(c.getInputStream());
		DataOutputStream dout = new DataOutputStream(c.getOutputStream());

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str, str1;

		while(!(str = din.readUTF()).equals("stop")){
			System.out.println("Client says: " + str);
			str1 = br.readLine();
			dout.writeUTF(str1);
			dout.flush();
		}		

		ss.close();
		c.close();
		din.close();
		dout.close();
		br.close();
	}
}
