#----SERVER SIDE----

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<stdlib.h>
int main(){
int welcomeSocket, newSocket;
char buffer[1024];
struct sockaddr_in serverAddr; 
struct sockaddr_storage serverStorage;
socklen_t addr_size;
welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(7891);
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
listen(welcomeSocket,10);
addr_size = sizeof serverAddr;
newSocket = accept(welcomeSocket, (struct  sockaddr *)	&serverStorage, &addr_size);
int counter = 0;
while(1)
{
	recv(newSocket,buffer,1024,0);
	printf("Frame %d received\n",counter);
	sleep(10);
	strcpy(buffer,"Frame received");
	send(newSocket,buffer,1024,0);
	printf("Acknowledgement sent\n");
	counter++;
}
return 0;
}

#----RECIEVER SIDE----

#include<math.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
int clientSocket;
char buffer[1024];
int m=1;
struct sockaddr_in serverAddr;
socklen_t addr_size;
int ack=1,i;
clientSocket = socket(PF_INET, SOCK_STREAM, 0);
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(7891);
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
connect(clientSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
int N;
scanf("%d",&N);
for(i=0;i<N;i++)
{
m=m+m; 
}
m=m-1;
for(i=0;i<m;i++)
{
strcpy(buffer,"Frame");
send(clientSocket,buffer,1024,0);
printf("Frame %d Sent\n",i+1);
}
int counter=0;
for(i=m;i<10;i++)
{
	ack=0;
	recv(clientSocket, buffer, 1024, 0);
	printf("\nAcknowledgement recieved for frame %d\n",counter); ack=1;
	counter++; if(ack==1)
	send(clientSocket,buffer,1024,0); printf("Frame %d sent",i+1); sleep(10);
}
return 0;
}
