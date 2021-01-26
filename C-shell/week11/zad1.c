#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int fd[2];
	pipe(fd);
	int pid=fork();
	if(pid==-1)
	{
		return 1;
	}
	else if (pid > 0)
	{
		close(1);
		dup(fd[1]);
		close (fd[0]);
		close (fd[1]);
		execlp("ls","ls",NULL);
		
	}
	else
	{
		close(0);
		dup(fd[0]);
		close(fd[1]);
		close(fd[0]);
		execlp("wc","wc", "-l",NULL);
		
	}
return 0;
}
