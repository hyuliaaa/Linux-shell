#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int pid=fork();

	if(pid==-1)
	{
		perror("Cannot fork");	
		return 1;
	}
	else if(pid >0)
	{
		

		printf("pid: %d\n",pid);
		execlp(argv[1],argv[1],NULL);
		exit(-1);
		
	}
	else
	{
		printf("curr pid %d\n",getpid());
		printf(" parent pid:%d\n",getppid());
		execlp(argv[2],argv[2],NULL);
		exit(-1);
	
		
	}

return 0;
}
