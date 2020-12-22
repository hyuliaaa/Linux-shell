#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd1=open(argv[1], O_RDONLY);
  if (fd1 ==-1)
  {
    printf("Error! Could not open the file");
    return 1;
   } 
	int fd2=open(argv[2], O_CREAT | O_RDWR, 0664);
	if(fd2==-1)
  {
    printf("Error! Could not open the file");
    return 1;
  }
  char bytebuffer[1];
	while(read(fd1, bytebuffer,1) > 0)
	{
	write(fd2,bytebuffer,1);
	}
	close (fd1);
	close(fd2);
	return 0;
}
