#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <wait.h>
int main(int argc,char *argv[])
{
	int fd,i,k,status;
	k=dup(1);
	if(fork())
	{
		wait(&status);
	for(int i=0; i<=3; i++)
	{
		write(1,"hello1\n",5);
		execlp("wc","wc","-w","abc",NULL);
		if(fork())
		write(1,"hello2\n",7);
		else write (2,"hello3\n",7);
		}
	}
	else
	{
		close(1);
		if((fd=open(argv[1],O_RDWR))==-1)
		{
			printf("CANNOT OPEN");
			return 1;
		}
		write(1,"hello3\n",7);
	}
	write(1,"hello4\n",7);
	write(k,"hello5\n",7);
}
//in file: hello3
//         hello4


//st:output: hello5
//           hello5 abc
//abc: Let's go change the world!
