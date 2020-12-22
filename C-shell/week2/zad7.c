#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int fd=open(argv[1], O_RDONLY);

	if (fd==-1)
	{
		printf("File could not be opened");
		return 1;
	}
	for(int i=5; i>=1; i--)
	{	

		execlp("wc", "wc", "-c", argv[1], NULL);
	}
return 0;

}
//output -26 aa, aa is the name of the file which contains the alphabet
