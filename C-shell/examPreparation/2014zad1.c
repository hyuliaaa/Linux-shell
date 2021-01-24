#include <stdio.h>
#include <unistd.h>
#include  <fcntl.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int fdR=open(argv[1],O_RDONLY);
	if(fdR==-1)
	{
		return 1;
	}
	int fdW=open(argv[1],O_WRONLY | O_APPEND);
	if(fdW==-1)
	{
		return 1;
	}
	char buff[1];
	while(read(fdR,buff,1))
	{
		if(buff[0]>='0' && buff[0]<='9')
		{
			break;
		}
		write(fdW,buff,1);
	}
	while(read(fdR,buff,1))
	{
		write(1,buff,1);
	}
return 0;
}
