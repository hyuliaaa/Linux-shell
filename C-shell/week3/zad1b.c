#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main()
{
	int fd=creat("ff", 0777);

	if(fd==-1)
	{
		printf("Cannot open");
		return 1;
	}

	int fd1=open("ff", O_RDONLY);

	if(fd1==-1)
	{
		printf("Cannot open");
		return 1;
	}
	int fd2=open("ff", O_WRONLY);

	if(fd2==-1)
	{
		printf("Cannot open");
		return 1;
	}
	int fd3=open("ff", O_RDWR);
	
	if(fd3==-1)
	{
		printf("Cannot open");
		return 1;
	}
	write(fd3, "Hello", 5);
	write(fd2,"worlds",6);
	char buffer[6];
	read(fd1,buffer,6);
	write(1,buffer,6);
	printf("\n");
	close(fd2);
	write(fd3, "oops", 4);
	char arr[6]="";
	read(fd1,arr,6);
	write(1,arr,6);
	return 0;
}


//output
//worlds
//ops

//in file: worldoops
