#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd=open(argv[1], O_CREAT | O_WRONLY,0777);
	if(fd==-1)
	{	
		printf("Cannot open");
		return 1;
	}
	int pid=fork();
	if(pid==-1)
	{
		perror("Cannot fork");
	}
	else if (pid > 0)
	{
		write(fd,"HELLO",5);
	}
	else
	{
	int fd2=open(argv[2], O_CREAT | O_APPEND | O_WRONLY,0777);
	close(1);
	dup(fd2);
	write(1, "HELLO", 5);
        }	
return 0;
}
