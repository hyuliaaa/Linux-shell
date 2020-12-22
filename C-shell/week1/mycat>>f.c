#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc,char *argv[])
{
	int fd=open(argv[1],O_RDWR | O_CREAT,0777);
	if(fd==-1)
	{
		printf("Couldn't open/create file");
		return 1;
	}
	int size=lseek(fd,0,SEEK_END); //finding the size of the file
	char buff[1];
	if(size==0) //if file empty
	{
		while(read(0,buff,1)>0)
		{
			write(fd,buff,1);
		}
	}
	else //if not
	{
		lseek(fd,size,SEEK_SET); //go to end of the file, this will be the current position
		while(read(0,buff,1)>0)  //read from input
		{
		write(fd,buff,1); //write from end of the file 
		}
	}
	return 0;
}
