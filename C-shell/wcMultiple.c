#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int fd;
	int wordCount=0;
	int rowCount=0;
	int size;
	
	for(int i=1; i<argc; i++)
	{
		
	   wordCount=0;
	  rowCount=0;
		fd=open(argv[i], O_RDONLY);
		if(fd==-1)
		{
			printf("Couldn't open file");
		}
		char buff[1];
		while(read(fd,buff,1)>0)
		{
			if(buff[0]=='\n')
			{
				rowCount++;
			}
			if(buff[0]=='\t' || buff[0]==' ' || buff[0] == '\n')
			{
				wordCount++;
			}		
		}
		
		size=lseek(fd,0,SEEK_END);
	  printf("Rows = %d, wordCount=%d,size=%d, name=%s",rowCount,wordCount,size,argv[i]);
	  printf("\n");
	}
return 0;
}
