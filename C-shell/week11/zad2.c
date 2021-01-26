#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd[2];
	pipe(fd);
	int pid=fork();
	if(pid==-1)
	{
		return 1;
	}
	else if(pid>0)
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close (fd[1]);
		execlp(argv[1],argv[1],NULL);
	}
	else
	{
		close (0);
		dup(fd[0]);
		close(fd[0]);
		close (fd[1]);
		execlp(argv[2],argv[2], NULL);
	}
return 0;
}
