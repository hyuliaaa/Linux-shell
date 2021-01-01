#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int countRows(int fd)
{
	int rows=0;
	char buff[1];
	while(read(fd,buff,1))
	{
		if(buff[0] == '\n')
		{
			rows++;
		}
	}
return rows;
}

int main(int argc, char * argv[])
{
	int fd1=open(argv[2], O_RDONLY);
	int n=atoi( argv[1]);
	int rows=0;
	char buff[1];
	while(read(fd1,buff,1))
	{
		if(buff[0]=='\n')
		{
			rows++;
		}
		if(rows>=n)
		{
			write(1,buff,1);
		}
	}
	printf("%d", rows);
	return 0;
}
