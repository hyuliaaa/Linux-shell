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
	read(fd,buff,10); //Прочитаме първите 10 символа от файла и в момента offset-a е на позиция 10
	write(1,buff,10); //0123456789
	printf("\n"); 
	lseek(fd, 10, SEEK_CUR); // SEEK_CUR - отместването на файла става текуюата локация, която е е 10 + офсет байтс, който са 10 в случая
	read (fd,buff,10); // прочитаме 10 символа от 20-та позиция нататък
	write (1,buff,10);  // 5555555555
	}
	return 0;
}
