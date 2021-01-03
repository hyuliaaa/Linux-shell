#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
int main()
{
	int pid=fork();
	if(pid==-1)
	{
		printf("Could not fork");
		return 1;
	}
	else if (pid >0)
	{
	}
	else
	{
		int pid2=fork();
	}
	printf("pid= %d ppid= %d\n",getpid(),getppid());
	wait(NULL); wait(NULL);
return 0;
}
