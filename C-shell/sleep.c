#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
//Write a C program that executes the sleep command or 10 sec
int main()
{
	char *args[]={"sleep","10",NULL};
 	execv("/bin/sleep",args); // with execv we write the absolute path
	return 0;
}
