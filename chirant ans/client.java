import java.util.*;
import java.io.*;
import java.net.*;

public class client{
	public static void main(String[] args) throws IOException{
		Socket s = new Socket("localhost", 8000);

		DataInputStream din = new DataInputStream(s.getInputStream());
		DataOutputStream dout = new DataOutputStream(s.getOutputStream());

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str, str1;

		while(!(str = br.readLine()).equals("stop")){				
			dout.writeUTF(str);
			dout.flush();
			System.out.println("Server says: " + din.readUTF());
		}

		din.close();
		dout.close();
		s.close();
		br.close();
	}
}
