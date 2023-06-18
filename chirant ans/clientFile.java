import java.io.*;
import java.util.*;
import java.net.*;

public class clientFile{
	public static void main(String[] args) throws IOException{
		Socket s = new Socket("localhost", 8000);

		DataInputStream din = new DataInputStream(s.getInputStream());
		DataOutputStream dout = new DataOutputStream(s.getOutputStream());

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;

		System.out.println("Enter file name: ");

		while(!(str = br.readLine()).equals("stop")){
			
			dout.writeUTF(str);
			dout.flush();
			System.out.println("FIle: " + din.readUTF());				
		}

		din.close();
		dout.close();
		br.close();
		s.close();
	}
}
