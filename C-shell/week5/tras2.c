#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
#include       <wait.h>
int main (int argc, char * argv [ ] )
{ int fd, i=4, nb1,status;
  char buf [5];
        if ( fork ( )==0) {
             ++i;
            printf("Stoinostta na i= %d\n",i);
	}
       else  {
		--i;
		 exit(0);
		 wait ( &status) ;
         if ( execlp( "ls", "ls","-l",NULL) == -1) 
		i=i+1;
         else
            printf("Stoinostta na i= %d\n",i);
               }
      printf("Stoinostta na i= %d\n",i);
}
