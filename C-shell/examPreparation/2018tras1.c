#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int fdi, fdio, nb1,nb2;
	char buf[15];
	fdi=open("abc",O_RDONLY);
	fdio=open("abc", O_RDWR);
	nb1=read(fdi,buf,6);
	write(1,buf,nb1);
	lseek(fdi, 3 , SEEK_CUR);
	nb1=read(fdi,buf,6);
	lseek(fdio,-19,SEEK_END);
	write(fdio,"xxxx",4);
	write(1,buf,nb1); 
	write(fdio,"_123_",5);
	lseek(fdio,2,SEEK_CUR);
	nb2=read(fdio,buf,6);
	write(1,buf,nb2);
	write(1, "_abcd",5);
	lseek(fdi,-2,SEEK_END);
	nb2=read(fdi,buf,2);
	write(1,buf,nb2);
return 0;
}
//abc:Let's goxxxx_123_he world!
//std output: Let's change world_abcd!
