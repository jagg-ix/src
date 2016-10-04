#include <stdio.h>
int main()
{


typedef struct po{
	int x;
	int y ;
}point;

  point  vector[10];

int i=0 ;

point p1= { 10, 10 }, p2= {10 , 10  };
unsigned char *p=NULL;

for( ; i< 9; i++ ){
	vector[i].x = i;
	vector[i].y = i *2 ;
	printf("(%d,%d) \n", vector[i].x, vector[i].y 	);
}
	p=(unsigned char * ) vector+sizeof(int)*3;
	printf("%x \n", *p );	

if( p1== p2 ){
	printf(" las estructuras si se pueden comparar %d,%d == %d,%d \n", p1.x, p1.y, p2.x , p2.y );	
}	
return 0; 
}
