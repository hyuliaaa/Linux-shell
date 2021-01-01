#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{

	int fd1=open("f1", O_RDWR);
	if(fd1==-1)
	{
		printf("Could not open");
		return 1;
	}
	int fd2=open ("f1", O_RDWR);
	if(fd1==-1)
	{
		printf("Could'n open");
		return 1;
	}
	lseek(fd1,-2, SEEK_END);
	write(fd1,"wxyz",4);
	lseek(fd1, 5, SEEK_SET);
	write(fd1,"12",2);
	int position = lseek(fd1,0,SEEK_CUR); //find the current position of fd1
	printf("%d\n", position);
	
	int pos = lseek(fd2,0,SEEK_CUR); //find the current position of fd1
	printf("%d", pos);
return 0;
}
