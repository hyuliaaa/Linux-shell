#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <wait.h>
int main(int argc, char *argv[])
{

	int status=0;
	int pid=fork();
	if(pid==-1)
	{
		perror("Couln't fork");
		return 1;
	}
	else if(pid>0)
	{
		write(1,"from parent\n", 10);
		wait(&status);
		if(status==0)
		printf("%s",argv[1]);
	}
	else
	{
		
		if(execlp(argv[1],argv[1], NULL)==-1)
		{
			perror("EXEC Error");
			return 1;
		}
	}
	return 0;
}
