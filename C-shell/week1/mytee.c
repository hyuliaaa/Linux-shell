#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;
	char buffer[1000];
	scanf("%s",buffer);
	int len=strlen(buffer);
	printf("%d\n",len);
	for(int i=1;i<argc; i++)
	{
		fd=open(argv[i],O_WRONLY|O_CREAT,0777);
		if(fd==-1)
		{
			printf("Couldn't create file");
			return 1;
		}
			write(fd,buffer,len);
		close(fd);
	}
return 0;
}
