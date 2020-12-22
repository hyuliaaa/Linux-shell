#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

	int fd=open("aa", O_RDWR);
	if(fd==-1)
	{
		printf("Couldn't open file!");
		return 1;
	}
	
	for(int i=5; i>=1;i--)
	{
		
	char buff[5]={""};
		lseek(fd,3,SEEK_CUR); //chetem prez 3 ot tekyshtata poziciq
		read(fd,buff,i);
		printf("%s",buff);
		printf("\n");
	}
	close (fd);
return 0;
}
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25  
//a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//      _________        __________           _______           ______   

//dobavqme 0+3
//defg
