#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd1=open(argv[1],O_RDONLY);
	
	if(fd1==-1)
	{
		return 1;
	}
	char buffer[60];
	char c;
	int i=0;
	int fd=open(argv[1], O_RDONLY);		
	
			int fd2=open(argv[2], O_WRONLY | O_CREAT, 0777);
	while(read(fd,&c,1)>0){
	
		i=0;
	while(read(fd1,&c,1)>0 && c!='\n')
	{
		
		buffer[i]=c;
		i++;
  	
	}
		buffer[i]='\0';
		if(buffer[i-1]=='$')
		{
			write(1,buffer,i);
			printf("\n");

		}
		else
		{
			for(int j=0;buffer[j];j++)
			{
				if(buffer[j]>='0' && buffer [j]<='9')
				{
					write(fd2,&buffer[j],1);	
					
			        	if(!(buffer[j+1]>='0' && buffer [j+1]<='9'))
					{
						write(fd2,"\n",1);
						break;
					}
				}
			}
		}
	}
	execlp("wc","wc","-l", argv[2],NULL);
return 0;
}
