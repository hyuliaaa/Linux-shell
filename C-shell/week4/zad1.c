//file f-abcdefghijklmnoprstuvwxyz
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int fd=open("f", O_RDONLY);
	if(fd==-1) 
	{
		return 1;
	}
	int tmpfd=dup(fd); //makes a copy of fd, both of the fds move together
	char buff[5];
	read(fd,buff,5); read abcde
/	write(1,buff,5);//abcde
	write(1,"\n",1);
	read(tmpfd,buff,5); //read fghij
	write(1,buff,5); //fghij
	write(1,"\n",1);
	close(fd); 
	read(tmpfd,buff,5); //read klmno
	write(1,buff,5); //klmno
	
return 0;
}
