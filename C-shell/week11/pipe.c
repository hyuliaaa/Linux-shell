#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd[2];
	if(pipe(fd)==-1)
	{
		printf("an error has occured");
		return 1;
	}
	printf("fd[0] : %d\n", fd[0]);
		
	printf("fd[1] : %d", fd[1]);
return 0;
}
