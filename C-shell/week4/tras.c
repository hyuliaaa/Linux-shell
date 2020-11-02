#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>

main ( )
{
	int fd ;

	fd = dup ( 1 ) ; //dublirame 1, toest imame 3
	printf ( " fd = %d\n", fd ); //3

	write ( 1, "Hello", sizeof ("Hello" ) );
	write ( fd, "-guys" , sizeof ( "-guys" ) );
	write ( 1, "-and Goodbye!\n", 14 );

	close ( 1 );
	write ( 1, "No\n", sizeof ( "No\n" ) ) ;

	write ( fd, "Yes\n", sizeof ( "Yes\n" ) ) ;
} 
//Hello-guys-and Goodbye
//Yes
