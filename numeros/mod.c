#include <stdio.h>
#include <math.h>
int main()
{
int i=10;
int b=0;
for( ; i>=0 ; i-- )
{
	b= i %10;
	printf(" %d mod 10 = %d \n", i,b );
}
return 0 ; 
}
