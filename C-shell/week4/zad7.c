#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd=open(argv[1], O_RDONLY);
	if(fd==-1)
	{
		return 1;
	}
	int fd1=open(argv[2],O_WRONLY | O_CREAT, 0777);
	if(fd1==-1)
	{
		return 1;
	}
	close (0);
	int fd3=dup(fd);
	close(fd);
	close(1);
	int fd4=dup(fd1);
	close(fd1);
	char buff[1];
	while(read(fd3,buff,1)>0)
	{
	
		write(fd4,buff,1);	
	}
return 0;
}


