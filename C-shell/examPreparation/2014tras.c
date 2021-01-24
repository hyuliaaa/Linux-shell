#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[])
{
	int pid,fd;
	char buf[5];
	if((pid=fork())==-1)
	{
		write(2, "Fork failed\n",13);
		return 1;
	}
	if(pid!=0)
	{
		int status=0;
		wait(&status);	
		fd=open("asdf.txt", O_RDWR | O_APPEND);
		write(fd,"7",1);
		lseek(fd,0,SEEK_SET);
		int n=read(fd,buf,5);
		write(1,buf,n);
	}
	else
	{
		fd=open("asdf.txt", O_CREAT | O_WRONLY, 0644);
		dup2(fd,1);
		close(fd);
		execlp("echo","echo","123456",NULL); //еко пуска един нов ред
	}
	return 0;
}
//Забележка: Когато пренасочим изходите на детето, тези на родителя си остават непроменени!
//във файла: 12345
//           7
//ст.изход: 12345
/*
int dup2(int oldfd, int newfd);
   The dup2() system call performs the same task as dup(), but
       instead of using the lowest-numbered unused file descriptor, it
       uses the file descriptor number specified in newfd.  If the file
       descriptor newfd was previously open, it is silently closed
       before being reused.

*/
