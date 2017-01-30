#include<stdio.h>

extern Powernum( int x, int y ); /* Powernum is written in
                                     Powernum.asm */
int main( void )
{
	int x,y;
	printf("\nEnter base number: ");
	scanf("%d",&x);
	printf("\nEnter power number: ");
	scanf("%d",&y);
	printf( "\n%d^%d = %d \n", x,y,Powernum( x, y ) );
	return(0);
}