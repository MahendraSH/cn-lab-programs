import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class mod3Q16{
    public static void main(String[] args) throws IOException{
        ServerSocket ss = new ServerSocket(777);
        Socket c = ss.accept();

        System.out.println("Connection established!");

        DataInputStream din = new DataInputStream(c.getInputStream());
        DataOutputStream dout = new DataOutputStream(c.getOutputStream());

        int client;
        while((client = din.readInt()) != -1){
            System.out.println("Received num: " + client);
            int res = (client*client);
            dout.writeInt(res);
            dout.flush();
        }

        dout.close();
        din.close();
        ss.close();
        c.close();
    }
}