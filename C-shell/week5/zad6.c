#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{

	int status=0;
	int fd=open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd==-1)
	{
		return  1;
	}
  	int pid=fork();
	if(pid==-1)
	{
		return 1;
	}
	else if(pid>0)
	{
		wait(&status);
		write(fd,"HELLO",5);
	}else
	{
		write(fd,"HELLO",5);
	}
	return 0;
}

