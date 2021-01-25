#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <wait.h>
int main(int argc, char *argv[])
{
	int status=0;
	int fd2=open(argv[2],O_CREAT | O_TRUNC | O_WRONLY,0777);
	int fd3=open(argv[3],O_CREAT | O_TRUNC | O_WRONLY, 0777);	

	if(fork())
	{
		wait(&status);
		printf("Child finished with status %d", status);
	}
	else
	{
		dup2(fd2,1);
		dup2(fd3,2);
		execlp("tail","tail", "-2l", argv[1],NULL);
	
	}
	close(fd2);
	close(fd3);
return 0;
}
