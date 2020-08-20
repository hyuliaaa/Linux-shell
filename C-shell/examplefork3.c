#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	int a=1;
	int pid=fork();
	if (pid < 0)
	{
	printf("Couldn;t fork\n");
	}
	else if (pid > 0)
	{
		++a;
	}
	else
	{
	--a;
	}
	printf ("a=%d\n",a);  // a=2
                         //a=0;
	return 0;
}
