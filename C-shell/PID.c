#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int pid;
	pid=fork();  /create new process
	if(pid > 0)
	{
	printf("pid %d\n",pid); //the variable pid return the value of the PID of the child //11775
	printf("getpid %d", getpid());//gives the PID of the current process -11776
	}
	else if(pid==0)
	{
	
	printf("\nIN child\n");
	printf("pid %d\n",pid); //pid=0;
	printf("getpid %d", getpid());//PID=11775
}
	return 0;
}
