//получава 4 параметъра-имена на файлове
//съдържанието на 1 ф е една команда
//прочита и стартира командтата от ф 1
//стартрира командата wc -l с арг 2 подаден файл,като пренасочва стандартния й изход в 3
//а изхода й за грешки в 4
//Накрая извежда на екрана номера на завършилия процес, изпълняващ командара wc
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	
	int status=0;
	char buffer[10];
	char c;
	int i=0;
	int fd=open(argv[1],O_RDONLY);
	int fd2=open(argv[2], O_RDONLY);
	int fd3=open(argv[3],O_WRONLY| O_CREAT, 0777);
	int fd4=open(argv[4], O_WRONLY | O_CREAT, 0777);
	if(fork())
	{
		wait(&status);
		printf("PID %d\n", wait(&status));
	}
	
	else
	{
		int stat=0;
		if(fork())
		{
		
			wait(&stat);
			dup2(fd3,1);
			dup2(fd4,2);
			execlp("wc","wc","-l",argv[2],NULL);
			
		}

		else
		{
	
		    	while(read(fd,&c,1))
			{
				buffer[i]=c;
				i++;
			}
			buffer[i]='\0';
			execlp(buffer,buffer,NULL);
		}
	}
return 0;
}
