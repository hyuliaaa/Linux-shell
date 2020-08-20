#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
//файлът newfile.txt съдържа 0123456789abcdefghij5555555555
int main()
{
	int fd;
	char buff[10];
	fd=open("newfile.txt", O_RDWR);
	if(fd ==-1)
	{
	printf("Couldn't open the file");
	}
	else
	{
	read(fd,buff,10);
	write(1,buff,10);
	printf("\n");
	lseek(fd,5, SEEK_SET); // отместването на файла се намира на 5-та позиция
	read (fd,buff,10); // четем от позиция номер 5 символи с дължина 10 , следователно изходът е 56789abcde
	write (1,buff,10);
	}
	return 0;
}
