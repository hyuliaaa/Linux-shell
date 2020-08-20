
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
	int fd1=open("file1.txt", O_WRONLY | O_CREAT, 0777); //crating the file, we use O_WRONLY to be able to write to the file and to use the write command
	write(fd1,"Hello",6);
	write(fd1, "smth",5);
	close(fd1);
	return 0;
}
