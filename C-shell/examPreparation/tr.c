#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int fdi,fdio,nb1,nb2;
	char buf[15];
	fdi=open("F2",O_RDWR);
	fdio=open("F2",O_RDWR);
	
	lseek(fdio,-15,SEEK_END);
	nb2=read(fdio,buf,7);
	write(1,buf,nb2);
	
	lseek(fdi,3,SEEK_CUR);
	nb1=read(fdi,buf,8);
	write(1,buf,nb1);
	
	nb1=read(fdi,buf,3);	
	write(1,buf,nb1);
	
	lseek(fdi,10,SEEK_CUR);
	nb2=read(fdi,buf,6);
	
	lseek(fdio,3,SEEK_SET);
	write(fdio,buf,nb2);
	write(1,"disc",4);
	write(fdio," ",1);

	write(1,"overed",6);
	lseek(fdio,-2,SEEK_END);
	nb1=read(fdio,buf,2);
	write(1,buf,nb1);
}

