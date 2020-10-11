#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd;
	for(int i=1;i<argc; i++)
	{
		fd=open(argv[i],O_WRONLY|O_CREAT,0777);
		if(fd==-1)
		{
			printf("Couldn't create file");
			return 1;
		}
		char buff[1];  
		while(read(0,buff,1)>0)
		{ 
			write(fd,buff,1);
			write(1,buff,1);
		}
		close(fd);
	}
return 0;
}
//pishe vyv failove, sled kato sme priklyuchili pisaneto v 1 fail, natiskame ctrl+d i zapochvame da pishem v 2 i t.n.
