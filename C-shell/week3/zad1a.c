#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main()
{
	creat("fff", 0777); //file descriptor has value 3
	int fd1=open("fff", O_RDONLY);
	if(fd1==-1)
	{
		printf("Could not open the file");
		return 0;
	}
	int fd2=open("fff", O_WRONLY);
	if(fd2==-1)
	{
		printf("Could not open the file");
		return 0;
	}
	int fd3= open("fff", O_RDWR);
	if(fd3==-1)
	{
		printf("Could not open the file");
		return 0;
	}
	
	write(fd2, "Hello world",11);
	printf("\n");

	char buffer[6];
	read(fd3,buffer,6);
	write(1,buffer,6);

	printf("\n");
	char arr1[5];
	read(fd1,arr1,5);
	write(1,arr1,5);

	printf("\n");
	write(fd3,"chil",4);

	printf("\n");
	write (fd2, "!!!",3);
	
	printf("\n");
	char arr[9];
	read(fd1, arr,9);
	write(1,arr,9);
  
  close (fd1); //4
  close (fd2); //5
  close(fd3); //6
return 0;
}


//output :
//Hello 
//Hello


 //child!!!
 
 
// in "fff"  - Hello child!!!
