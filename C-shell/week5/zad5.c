
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[])
{
	for(int i=1; i<argc;i++)
	{
		int pid=fork();
		int status=0;
		if(pid==-1)
		{
			printf("Couldnt;t fork");
			return 1;
		}
		else if(pid>0)
		
		{
			printf("current processs id%d\n",getpid());
			wait(&status);
			if(status==0)
			{
				printf("%d\n",pid);
			}
		}
		else
		{
			if(execlp(argv[i],argv[i],NULL)==-1)
			{
				perror("EXEC ERROR");	
				return 1;
			}
		}
	}
	return 0;
}

//./a.out date ls ps
current processs id 1577
Tue Nov  3 17:30:01 EET 2020
1578
current processs id1577
a.out  file  newfile  zad1.c  zad2.c  zad3.c  zad5.c
1579
current processs id 1577
  PID TTY          TIME CMD
 1577 pts/0    00:00:00 a.out
 1580 pts/0    00:00:00 ps
14086 pts/0    00:00:00 bash
1580
