#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{

	execlp("grep","grep", "int", argv[1],NULL);
	printf("Never printed);
	return 0;
}
