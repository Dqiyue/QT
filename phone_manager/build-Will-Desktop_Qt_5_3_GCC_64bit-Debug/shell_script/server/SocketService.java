import java.net.*;  
import java.io.*;  
  
public class SocketService {  
    private ServerSocket server;  
    private Socket client;   
    private BufferedReader in;  
    private PrintWriter out;  
    public boolean execute(String ip) {  
//      LogUtil.LogCommInfo("------修改权限路劲 path="+path);  
        boolean flag   = false ;  
        try{              
            String cmdStr[] = new String[]{"adb","connect",ip}; 
            Process child = Runtime.getRuntime().exec(cmdStr);  
            System.out.println("exec right");
//          child.waitFor();  
            flag =  true ;  
        }catch(Exception e){  
            flag =  false ;  
//          LogUtil.LogCommInfo("修改权限异常 = "+e);  
            e.printStackTrace();  
        }  
        return flag ;  
    }  
        public boolean executePullContacts() {  
//      LogUtil.LogCommInfo("------修改权限路劲 path="+path);  
        boolean flag   = false ;  
        try{              
            String cmdStr[] = new String[]{"adb","pull","/sdcard/我的联系人.txt","./我的联系人"}; 
            Process child = Runtime.getRuntime().exec(cmdStr);  
            System.out.println("pull contacts right");
//          child.waitFor();  
            flag =  true ;  
        }catch(Exception e){  
            flag =  false ;  
//          LogUtil.LogCommInfo("修改权限异常 = "+e);  
            e.printStackTrace();  
        }  
        return flag ;  
    } 
    public SocketService() {  
        try {  
            server = new ServerSocket(9400);  
            while(true){  
             System.out.println("start receving！");  
            //获得客户端连接  
             client = server.accept();  
             //获得客户端的IP和端口  
             String remoteIP = client.getInetAddress().getHostAddress();  
             int remotePort = client.getLocalPort();  
              
             System.out.println("A client connected. IP:" + remoteIP + ", Port: " + remotePort);  
             System.out.println();  
             execute(remoteIP);
             //获得 client 端的输入输出流，接收标志位，用于提取联系人
             in = new BufferedReader(new InputStreamReader(client.getInputStream()));  
             out = new PrintWriter(client.getOutputStream(),false);  
             System.out.println(in);
             //获得 client 端发送的数据  
             String tmp = in.readLine();  
             if(tmp  == "1\n"){
                //提取联系人
            	 System.out.println(tmp);
                //executePullContacts();
             }
//           String content = new String(tmp.getBytes("utf-8"));  
             System.out.println("Client message is: " + tmp);  
              
            // 向 client 端发送响应数据   
             System.out.println("Your message has been received successfully！.");  
              
             //关闭各个流  
            out.close();  
            in.close(); 
             //server.close();      套接字未关闭，不关闭会有后台开着
            }   
           }catch(Exception e){  
           // 发送响应，接收失败  
               System.out.println(e.toString());  
            out.println("Receive Error!");  
           }  
    }  
  
    public static void main(String[] args) {  
        new SocketService();  
    }  
}  