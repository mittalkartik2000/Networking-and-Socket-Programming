# ---- SENDER ----
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int k=0;
int main()
{
int welcomeSocket,newSocket,i,result;
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
newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
while(1)
	{
	recv(newSocket,buffer,1024,0);
	result=strcmp(buffer,"end");
	if(result!=0)
		{
		printf("%s %d received\n",buffer,k+1);
		k=k+1;
		}
	else
	{
	sleep(5);
	strcpy(buffer,"Frame received");
	send(newSocket,buffer,1024,0);
	printf("Acknowledgement sent\n");
	}
return 0;
}

#----RECEIVER----

#include<stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int k=0;
int main()
{
int clientSocket;
char buffer[1024];
struct sockaddr_in serverAddr;
socklen_t addr_size;
int ack=1,i,w,n; 
clientSocket = socket(PF_INET, SOCK_STREAM, 0);
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(7891);
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
connect(clientSocket,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
printf("Enter the window size:\n");
scanf("%d",&w);
printf("Enter the number of frames:\n");
scanf("%d",&n);
int n1=n;
while(1)
{
if(ack==1)
{
	n1=n1-w;
	if(n1>0)
	{
	
	for(i=0;i<w;i++)
	{
		strcpy(buffer,"Frame");
		send(clientSocket,buffer,1024,0);
		printf("Frame %d Sent\n",k+1);
		k=k+1;
	}
	strcpy(buffer,"end");
	send(clientSocket,buffer,1024,0);
	}
	else
	{
		for(i=0;i<n1+w;i++)
		{
			strcpy(buffer,"Frame");
			send(clientSocket,buffer,1024,0);
			printf("Frame %d Sent\n",k+1);
			k=k+1;
		}
		break;
	}
}
ack=0;
recv(clientSocket, buffer, 1024, 0);
printf("Sent by server:%s\n",buffer);
ack=1;
sleep(5);
}
return 0; 
}

