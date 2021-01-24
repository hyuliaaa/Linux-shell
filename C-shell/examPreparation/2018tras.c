#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
int main(int argc,char *argv[])
{
	int fd,i,status;
	if(fork())
	{
	wait(&status);
	for(int i=0; i<=3;i++)
     		{
		write(1,"hello1\n",5);
		execlp("wc","wc","-w","abc",NULL);
		write(1,"hello2\n",5);
        	}
	}
	else
	{
		close(1);
		fd=open(argv[1],O_RDWR);
		write(1,"hello3\n",7);
	}
	write(1,"hello4\n",7);
return 0;
}

//fail:hello3
//     hello4
//st.output: hello5 abc
