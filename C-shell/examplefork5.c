#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int pid=fork();
	if (pid==-1)
	{
	printf("Couldn;t fork");
	}
	else if (pid > 0)
	{
	printf("My process ID is %d and my parent ID is %d\n", getpid(),getppid());
	}
	else
	{
	printf("My process ID is %d and my parent ID is %d\n",getpid(),getppid());        }
printf("smth\n");
return 0;
}
