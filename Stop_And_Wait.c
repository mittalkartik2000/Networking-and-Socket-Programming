# ----- SENDER -----

#include<math.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
int clientSocket;
int welcomeSocket,newSocket char buffer[1024];
 
struct sockaddr_in serverAddr;
struct sockaddr_storage serverStorage; socklen_t addr_size;
welcomeSocket=socket(PF_INET,SOCK_STREAM,0); serverAddr.sin_family  =  AF_INET; serverAddr.sin_port = htons(7891); serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); addrsize=sizeof(serverAddr);
blind(welcomeSocket,(struct sockaddr*) &serverAddr, &addrsize); listen(welcomeSocket,10);
newSocket=accept(welcomeSocket,(struct sockaddr *) &serverStorage,&addrsize while(1>0)
{
recv(newSocket,buffer,1024,0); printf(“\nFrame reveived \n“); sleep(10);
strcpy(buffer,”Frame received”) send(newSocket,buffer,1024,0); printf(“\nACK sent\n);
}
return 0;
}


# ---- RECEIVER ----

#include<math.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
int clientSocket; char buffer[1024]; int m=1;
struct sockaddr_in serverAddr; socklen_t addr_size;
int ack=1,i;
clientSocket = socket(PF_INET, SOCK_STREAM, 0); serverAddr.sin_family = AF_INET; serverAddr.sin_port = htons(7891); serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
connect(clientSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr)); int N=15;
for(i=0;i<N;i++)
{
if(ack==1){ strcpy(buffer,"Frame");
 
send(clientSocket,buffer,1024,0); printf("Frame %d Sent\n",i+1); ack=0;
recv(clientSocket, buffer, 1024, 0); printf("\nAcknowledgement recieved for serv %s\n",buffer); ack=1;

sleep(10);
}
}
return 0;
}

