#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
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
		write(fd,"hello1",6);
	}
	else
	{
		close(1);
		dup(fd2);
		write(1,"hello2\n",6);
	}
	write(1,"hello3\n",6);
	write(fd2, "hello4\n",6);
	
return 0;
}


//When we fork, there are two processes
//In the parent first we write to f1(argv[1]) "Hello1"
//then we go to the common part and write to the standart output "hello3"
//and we write to argv[2] :"hello4"
//In the child we close the standart ouput and make it point to the argv[2]
//we write "hello2" in argv[2], then in the common part
//we write "hello3 in argv[2] because we have changed the st oupyt and we write "hello4" in argv[2]

//output:
//hello3
//in f1: "hello1"
//in f2: "hello4,hello2,hello3,hello4
