#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <stdlib.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int status=0;
	int returnedCode=0;
	int pid=fork();
	if(pid==-1)
	{
		perror("Couldn;t fork");
		return 1;
	}
	else if(pid>0)
	{
		printf("IN PARENT\n");
		int pid=wait(&status);
		printf("My child has finished with status %d\n",status); //status parameter of wait, gives the return code of the child-process
    printf("PID OF CHILD %d\n, pid);
	}
	
	else
	{
		execlp(argv[1],argv[1], argv[2],NULL);
		exit(returnedCode);
		printf("ERROR");
		return 1;
	}
return 0;
}
//my child has finished with status 0
//pid of child: 14017
