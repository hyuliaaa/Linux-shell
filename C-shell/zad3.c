#include <stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
/*
Чете последователност от символи от файл, чието име е подадено като първи параметър. 
Извежда ги на стандартния изход. 
Първите 3 символа от всеки ред добавя след края на файл, чието име е подадено като втори параметър.
*/
int main(int argc, char *argv[])
{
	int fd1=open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
	   printf("Couldn't opem the file");
	   return 1;
	}
	int fd2=open(argv[2], O_CREAT | O_APPEND | O_WRONLY, 0664);
	if(fd2==-1)
	{
	   printf("Couldn-t opem the file");
	   return 1;
	}
	 har buff[1];
	int bytesCount=0;
	while(read(fd1,buff,1)>0)
	{
         write (1, buff,1);
	       if(bytesCount < 3)
	       {
		          write(fd2,buff,1);
		          ++bytesCount;
	       }
	       else
	       {
		         if(buff[0]=='\n')
		          bytesCount=0;	
        	}	
   }
	close(fd1);
	close(fd2);
	return 0;
}
