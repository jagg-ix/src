#include <stdio.h>
int main()
{
	FILE *input=NULL;
	short x,y;

input=fopen("datos.txt", "r+t") ;
fscanf( input,"%d",&x);
fscanf( input,"%d",&y);

printf("%d, %d \n", x, y );
return 0; 
}	
