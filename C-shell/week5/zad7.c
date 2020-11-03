#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int readBytes;
	int status=0;
	int pid=fork();
		int fd=open(argv[1],O_CREAT | O_TRUNC | O_RDWR,0777);
	if(pid==-1)
	{
		return 1;
	}
	else if(pid > 0)
	{
		wait(&status);
	
		char buffer[2]={""};
		while((readBytes=read(fd,buffer,2))>0)
		{
			//printf("%d", readBytes);
			write(1,buffer,readBytes);
			write(1," ",1);
		}
		

	}
	else
	{
		if(fd==-1)
		{
			return 1;
		}
		write(fd,"Hello",5);
	}
return 0;
}
