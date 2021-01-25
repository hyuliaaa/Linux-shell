
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	int fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		return 1;
	}
	int fd2=open(argv[2],O_CREAT | O_WRONLY | O_APPEND, 0664);
	if(fd2==-1)
	{
		return 1;
	}

	char c1;
	char c2;
	while(read(fd,&c1,1) && read(0,&c2,1))
	{
		if(!(c1 >='0' && c1<='9'))
		{
			write(fd2,&c1,1);
		}
		
		if(!(c2 >='0' && c2<='9'))
		{
			write(fd2,&c2,1);
		}
	}
	close(fd);
	close(fd2);
		
	return 0;
}
