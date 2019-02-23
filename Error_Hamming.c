#---SENDER---
#include<stdio.h>
#include<string.h>
int main()
{
char s[1000];
int i,count=0;
printf("Enter the data: ");
scanf("%s",s);
for(i=0;s[i]!='\0';i++)
{
	if(s[i]=='1')
	{
		count=count+1;
	}
}
if(count%2==0)
	count=0;
else
	count=1;

printf("Enter the data recieved: ");
scanf("%s",s);or(i=0;s[i]!='\0';i++)
{
	if(s[i]=='1')
	{
		count=count+1;
	}
}
if(count%2==0)
{
	printf("\nNo error\n");
}
else
	printf("\nError in 1 bit\n");
 
return 0;
}
