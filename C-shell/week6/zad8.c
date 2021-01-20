#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int status=0;
	int pid=fork();
	if(pid==-1)
	{
		perror("Could not fork");
		return 1;
	}
	else if(pid >0)
	{
		wait(&status);
		if(status==0)
		execlp(argv[2],argv[2],NULL);
		exit(-1);
	}
	else
	{
		execlp(argv[1],argv[1],NULL);
		exit (-1);

	}
return 0;
}
