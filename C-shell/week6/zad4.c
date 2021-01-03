#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int fd=open(argv[1], O_CREAT|O_TRUNC| O_WRONLY,0777);
	if (fd==-1)
	{
		printf("Cannot be opened");
		return 1;
	}
	int pid=fork();
	if(pid==-1)
	{
		perror("Cannot fork");
		return 1;
	}	
	else if (pid > 0)
	{
		write(fd,"hello1",6);
	}
	else
	{
		write(fd,"hello2",6);
	}
return 0;
}
//both of the process use the same file descriptor,it is inherited
//output can be: hello1hello2 or hello2hello1
