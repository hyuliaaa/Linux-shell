#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd=open(argv[1], O_RDONLY);
	if(fd ==-1)
	{
		printf("Cannot open the file");
		return 1;
	}
	int rows=0;
	int words=0;
	char buff[1];
	while( read(fd,buff,1)>0)
	{
		if(buff[0]=='\n')
		{
			rows++;
		}
		if (buff[0]=='\t' || buff[0]==' ' || buff[0]=='\n') 
		{
			words++;
		}
	}
	int size=lseek(fd,0,SEEK_END);
	printf("Rows = %d, word=%d,size=%d, name=%s",rows,words,size,argv[1]);
	return 0;
}
