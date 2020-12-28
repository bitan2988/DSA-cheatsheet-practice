import socket

Header = 64       
Port = 6060
Server = "192.168.0.105"
Format = 'utf-8'         
Disconnect_msg = "!DISCONNECT"
Addr = (Server, Port)

client  = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(Addr)

def send(msg):
    message = msg.encode(Format)
    msg_length = len(message)
    send_length = str(msg_length).encode(Format)
    send_length += b' ' * (Header - len(send_length))      #Make the header of exact 64 bit (b' ' --> byte representation of space)
    client.send(send_length)
    client.send(message)
    print((client.recv(2048)).decode(Format))            #receive message from server of anything less than byte size 2048 

x = " "
while(x!=Disconnect_msg):
    x = input()
    send(x)


