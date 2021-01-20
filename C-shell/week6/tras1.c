#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
#include <wait.h>
int main (int argc, char * argv [ ] )
{ int fd, j, nb1;
	int status=0;
  char buf [5];
        if ( fork ( ))
        { 
		             wait (&status ) ; execlp ( "cat", "cat", "fileA.txt" , NULL); 
        }
        else { j = dup ( 1 );
               fd = open ( argv [1], O_RDWR );
               nb1 = read ( 0, buf, 5 ); //hhhhh, we are reading this
               write ( j, buf, nb1 ); //write hhhhh to st. output
               nb1 = read ( fd, buf, 5 ); //read 01234
               write ( 1, buf, nb1 ); //write 01234 to sd.output
               write ( fd, "\n", 1 ) ; //put new line in file
               write ( fd, buf, nb1 ); //write 01234 in file
               write ( j, buf, 3 ); //write 012 to st. output
               close ( fd ); close ( j );       
               exit(0);
            }
}


//fileA.txt

//0123456789


//st output: hhhhh01234012
//in file: 01234
//          01234     
