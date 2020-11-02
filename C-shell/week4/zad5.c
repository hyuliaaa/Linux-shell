#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	for(int i=0; i<10;i++)
	{
		write(1,"EXAMPLE\n",8);
	}
	
	char str[50];
	for(int i=0; i<10;i++)
	{
		sprintf(str,"i=%d\n",i);
		write(1,str,strlen(str));
	}
	
	for(int i=0; i<10; i++)
	{
		write(1,"HELLO\n",6);
	}
	return 0;
}
