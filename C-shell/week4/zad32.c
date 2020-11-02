#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd=open("file", O_CREAT| O_WRONLY, 0777);
	close(1);
	int newfd=dup(fd);
	for(int i=0; i<10;i++)
	{
		write(newfd,"EXAMPLE\n",8);
	}
	close(fd);
	return 0;
	
}
