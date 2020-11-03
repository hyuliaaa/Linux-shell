#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
int main(int argc, char *argv[])
{
	int fd=open(arv[1], O_RDWR);
	int pid==fork();
	if(pid==-1)
	{
		perror("Couldn;t fork");
		return 1;
	}
	else if(pid >0)
	{
		wait(&status);
	}
	else
	{
		
:wq	

