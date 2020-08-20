#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int pid=fork(); // имаме 2 процеса- родител, дете
	if(pid == -1 )
	{
	perror ("Couldn't fork\n");
	}
	else if (pid > 0) //ако пид-а е > 0 сме в родителя
	{
	printf("Hello from the parent\n");
	}
	else  // ако пида е 0 сме в детето
	{
	printf("Hello from the child\n");
	}
	printf("Called fork()\n");
	return 0;
}
