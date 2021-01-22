#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int status=0;
	int fd=open(argv[3],O_CREAT | O_RDWR,0777);
	if(fd==-1)
	{
		return 1;
	}
	int pid=fork();
	if(pid==-1)
	{
		printf("Could not fork");
		return 1;
	}
	else if (pid>0)
	{
		wait(&status);
		if(status==0)
		{
			write(fd,argv[1],strlen(argv[1]));
		}
		execlp(argv[2],argv[2],NULL);
		
	}
	else
	{
			if(	execlp(argv[1],argv[1],NULL)==-1) 	
			{
				printf("Wrong command");
			}
	}
return 0;
}
