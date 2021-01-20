#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	int fd=open(argv[3], O_CREAT |O_WRONLY, 0777);
	int status=0;
	int pid=fork();
	if(pid==-1)
	{
		perror("Cannot fork");
	}
	else if (pid >0)
	{
		wait(&status);
		if(status==0)
		{
		write(fd,argv[1], strlen(argv[1]));
		execlp(argv[2],argv[2],NULL);
		}
		else
		{
      //sabina kaza na upr
      //close (0);
      //open("letter", O_RDONLY);
      //execlp("write","write",sabina,0);
			printf("UNSUCCESSFUL");
			exit(-1);
		}
	}
	else
	{
		if(	execlp(argv[1],argv[1],NULL)==-1)
		{
		exit(-1);
		}
	}
return 0;
}
