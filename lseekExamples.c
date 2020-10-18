#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
//aa file contains tha alphabet : abcdefghijklmnopqrstuvwxyz
int main()
{

	int fd=open("aa", O_RDWR);
	if(fd==-1)
	{
		printf("Couldn't open file!");
		return 1;
	}
	
	for(int i=5; i>=1;i--)
	{
		
	char buff[5]={""};
		lseek(fd,0,0); //sets the fd to the first character of the file
		read(fd,buff,i);
		printf("%s",buff);
		printf("\n");
	}
	close (fd);
return 0;
}
//after completing the program the result will be
//abcde
//abcd
//abc
//ab
//a
