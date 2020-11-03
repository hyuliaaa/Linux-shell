#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char *argv[])
{
	for(int i=0; i<10;i++)
	{
		write(1,"EXAMPLE\n",8);
	}
	int fd=open(argv[1],O_CREAT| O_WRONLY, 0777);
	if(fd==-1)
	{
		return 1;
	}
	int newfd=dup(1);
	close(1);
	int nfd=dup(fd);
	close(fd);
	
	char str[50];
	for(int i=0; i<10;i++)
	{
		sprintf(str,"i=%d\n",i);
		write(nfd,str,strlen(str));
	}
	close(nfd);
	int fd3=dup(newfd);	
	close(newfd);
	printf("%d",fd3);
	
	for(int i=0; i<10; i++)
	{
		write(fd3,"HELLO\n",6);
	}
	
	return 0;
}
