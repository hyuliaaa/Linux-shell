#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int rowCount=0;
	int fd;
	char buff[1];
	fd=open(argv[1], O_RDONLY);
	if(fd==-1)
	{
		printf("Couldn't open file");
		return 1;
	}
	while(read(fd,buff,1)>0)
	{
		if(buff[0]=='\n')
		{
	 		rowCount++;
		}
		
			write(1,buff,1);
		if(rowCount==10)
		{
			break;
		}
	}
	close(fd);
return 0;
}  
