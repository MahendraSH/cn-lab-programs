import java.io.*;
import java.util.*;
import java.net.*;

public class serverFile{
	public static void main(String[] args) throws IOException{
		ServerSocket ss = new ServerSocket(8000);
		Socket c = ss.accept();

		DataInputStream din = new DataInputStream(c.getInputStream());
		DataOutputStream dout = new DataOutputStream(c.getOutputStream());
		
		String str, str1;
		while(!(str = din.readUTF()).equals("stop")){
			System.out.println("File requested: " + str);
			FileInputStream fin = new FileInputStream("/home/chiranthkrishnak/CN/P2/" + str);
			BufferedReader fbr = new BufferedReader(new InputStreamReader(fin));
			while((str1 = fbr.readLine()) != null){
				dout.writeUTF(str1);
				dout.flush();
			}

			fbr.close();
			fin.close();
		}

		din.close();
		dout.close();
		c.close();
		ss.close();
	}
}
