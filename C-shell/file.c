//gcc file.c
//./a.out proba

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	int fd1=open(argv[1], O_WRONLY | O_CREAT | O_EXCL | O_APPEND, 0777); //създава се файлът проба и насовчаме фд1
	int fd2=open(argv[1], O_WRONLY); //насочваме и фд2 към проба
	printf("fd1= %d\n",fd1);
	printf("fd2= %d",fd2);
	write(fd1, "Hellobaby", 10);  //пишем hellobaby в проба
	write(fd2, "akula", 5); // новият файлов дескриптор започва да пише на началното място затова презаписва някоя от информацията и имаме akulababy
	close(fd1);
	close(fd2);
	return 0;
}
