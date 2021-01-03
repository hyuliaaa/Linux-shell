#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
	int pid1=fork();
	int pid2=fork();
	printf("pid= %d and ppid= %d\n",getpid(),getppid());

return 0;
}
