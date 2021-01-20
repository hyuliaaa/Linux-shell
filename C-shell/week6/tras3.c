#include        <stdio.h>
#include        <unistd.h>
#include        <fcntl.h>
#define    CMD   "who"
main ()
{ int fd, i=2,k=0, status;
        if ( fork ())
        { wait (&status) ;
             i--; k--;
             write(1, "exam1\n",6);
             printf("I=%d K= %d \n",i,k);
        }
        else 
        {
            for ( k=1; k<=3; k++)
            {  write(1, "exam2\n",6);
               i=k+i;
               printf("I=%d K=%d\n",i,k);
               if ((execlp ( CMD, CMD , 0)) == -1)
                write(1, "exam3\n",6);
               printf("I=%d K=%d\n",i,k);
            }
         }
       write( 1, "exam4\n",6);
       if ((execlp("ls","ls",0))== -1 )
          printf("I=%d K=%d\n",i,k);
       else {write ( 1, "exam5\n",6);}
}



/*
exam2
I=3 K=1
ubuntu   :0           2020-12-22 12:37 (:0)
exam1
I=1 K= -1 
exam4
'CLUTTER_IM_MODULE=xim'   fileA.txt   tras3.c   zad3.c	  zad7.a    zad9.c
 a.out			  prob.c      zad1.c    zad5a.c   zad7.c
 f			  s	      zad10.c   zad5b.c   zad7a.c
 ff			  tras1.c     zad2.c    zad6.c	  zad8.c
*/

