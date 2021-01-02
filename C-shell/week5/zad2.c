#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{

	execlp("grp","grp", "int", argv[1],NULL); //след като командата е грешна се преминава към втория ред, иначе не се
	printf("Never printed");
	return 0;
}
