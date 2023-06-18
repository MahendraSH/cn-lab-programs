import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Scanner;
import java.net.Socket;

public class mod3Q16a {
    public static void main(String[] args) throws IOException{
        Socket s = new Socket("localhost", 777);

        DataInputStream din = new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());

        Scanner si = new Scanner(System.in);
        int num;

        System.out.println("Enter a number to find sqaure: ");

        while((num = si.nextInt()) != -1){                        
            dout.writeInt(num);
            dout.flush();
            System.out.println("Server says: " + din.readInt());
            System.out.println("Enter a number to find sqaure: ");
        }

        dout.close();
        din.close();
        s.close();
        si.close();
    }
}
