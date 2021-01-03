#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int status=0;
	int fd=open(argv[1], O_CREAT|O_TRUNC| O_WRONLY,0777);

		int fd2=open(argv[2], O_CREAT| O_WRONLY,0777);
	if (fd==-1)
	{
		printf("Cannot be opened");
		return 1;
	}
	int pid=fork();
	if(pid==-1)
	{
		perror("Cannot fork");
		return 1;
	}	
	else if (pid > 0)
	{
		wait(&status);
		write(fd,"hello1",6);
	}
	else
	{
	int nf=	dup(1);
		close(1);
		dup(fd2);
		write(1,"hello2\n",6);
		close(1);
		dup(nf);

	}
	write(1,"hello3\n",6);
	write(fd2, "hello4\n",6);
	
return 0;
}


//output: hello3 hello3
//f1:hello1
//f2:hello2hello4hello4
