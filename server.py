import socket
import threading

Header = 64       #Every single message from client will  first send this header of length 64 which tells us about the length of the  incoming message
Port = 6060                     #Port we are trying to communicate on (try something in the range (2,000-65,535))
Server = "192.168.0.105"               #for local host communication use your own  ip  address
Server = socket.gethostbyname(socket.gethostname())        #get the ip of the host for us    gethostname-->name of our  computer
Addr = (Server, Port)    #when we will bind it then it should be a touple with sever at index 0 and port at index 1
Format = 'utf-8'         #encoding
Disconnect_msg = "!DISCONNECT"       #Message from client to disconnect from the server

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)       #get socket from a family of AF_INET which basically means IPV4     SOCK_STREAM-->streaming data through the socket
server.bind(Addr)       #Binding this address to this  socket i.e anything that hits this address will automatically hit this socket

def handle_client(conn, addr):         #interact with the clients
    print(f"[NEW CONNECTION] {addr} connected......")          
    connected = True
    while connected:
        msg_length = conn.recv(Header).decode(Format)           # will receive the message and decode it from its bytes format to a string
        if(msg_length):
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(Format) 
            print(f"[{addr}] --> {msg}")                      #receive message of message_length bytes
            if(msg==Disconnect_msg):
                connected = False
                print("DISCONNECTED FORM SERVER")
            conn.send("MSG RECEIVED".encode(Format))            #From server to client
    conn.close()



def start():      #Will star our  server to connect to clients
    server.listen()      #open the ports  for listening
    print(f"[LISTENING] Server is at IP = {Server} and listening on PORT = {Port}")
    while(1):
        conn,  addr = server.accept()       #when a new connnection occurs  it wil store the address(Ip and port) in addr  conn--> a socket oject that will allow us to  communicate back to the connection
        thread = threading.Thread(target=handle_client, args=(conn, addr))    #allow threading of this user defined function
        thread.start()      #start the thread
        print(f"[ACTIVE CONNECTIONS] = {threading.activeCount() -  1}")          #NO. of active threads = number of clients connecting to us -1 as start() thread is always running

print("[STARTING]  SERVER IS STARTING..........")
start()