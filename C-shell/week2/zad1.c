#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
//the file contains the alhabet
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
		read(fd,buffer,i);
		printf("%s\n", buffer);
	}
	return 0;
}
//output
//abcde
//fghie
//jklie
//mnlie
//onlie

