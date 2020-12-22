#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int fd=open(argv[1], O_RDONLY);
	if (fd==-1)
	{
		printf("Could not open the file");
		return 1;
	}
	char buffer[16]="";
	for(int i=5; i>=1; i--)
	{
		lseek(fd,-3,SEEK_END);
		read(fd,buffer,i);
		write(1,buffer,i);
		printf("\n");
	}
	return 0;
}
//output
//xyz
//xyz
//xyz
//xy
//x

