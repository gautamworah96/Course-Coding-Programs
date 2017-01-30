#include<stdio.h>

extern Addnum( int x, int y ); /* Addnum is written in
                                     Addnum.asm */
int main( void )
{
	printf( "5+100 = %d \n", Addnum( 5, 100 ) );
	return(0);
} 
