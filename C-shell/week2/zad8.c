#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main (int argc, char *argv[])
{
	int fd= open (argv[1], O_RDONLY);
	if (fd==-1)
	{
		printf ("Could not open  file");
		return 1;
	}
	
	char buffer[10];
	while (read(fd,buffer,10))
	{
		
	
		write(1,buffer,10);
		printf("\n");
	}
return 0;
}
//output - reads 10 symbols but in the last one we have excess which has been left from the previous reading
//abcdefghij
//klmnopqrst
//uvwxyzqrst
