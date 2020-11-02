#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	close(1);
	int fd=open("file", O_CREAT| O_WRONLY, 0777);
	printf("%d",fd);
	for(int i=0; i<10;i++)
	{
		write(fd,"EXAMPLE\n",8);
	}
	return 0;
	
}
