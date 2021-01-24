//Напишете програма на С, която:
//1.Приема име на файл като първи позиционен аргумент и го отваря веднъж за четене и веднъж за писане
//2.Ако файлът не може да бъде отворен, изведете грешка на ст.изход за грешки и прекратете програмата
//3.Чете от файла символ по символ и всеки прочетен символ го записва в края на файла,докато не срещне цифра
//4.Когато срещне цифра, записва останалата част от файла на ст.изход
#include <stdio.h>
#include <unistd.h>
#include  <fcntl.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int fdR=open(argv[1],O_RDONLY);
	if(fdR==-1)
	{
		write(2,"ERROR",5);
		return 1;
	}
	int fdW=open(argv[1],O_WRONLY | O_APPEND);
	if(fdW==-1)
	{
		write(2,"ERROR,5);
		return 1;
	}
	char buff[1];
	while(read(fdR,buff,1))
	{
		if(buff[0]>='0' && buff[0]<='9')
		{
			break;
		}
		write(fdW,buff,1);
	}
	while(read(fdR,buff,1))
	{
		write(1,buff,1);
	}
return 0;
}
