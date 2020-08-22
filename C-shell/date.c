#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//write C program which executes command date
int main()
{

	char *args[]={"date",  NULL}; //the first one is the name of the file in our case date
	execvp("date",args); // execvp searches in the directories which are in PATH 
	printf("Never printd"); //this line is never executed
	return 0;
}
