#include <stdio.h>
#include <math.h>

int main(){

double n=0;
unsigned int i=0;
unsigned int k=0;
for( ; k<=2  ; k++ ){

	for(i=0 ; i<=1000; i++ ){
		n= i * i* i;
		//n= exp( 3 * log( i ) );
		printf("cubo de %d = %f \n", i, n);
	}
}

return 0 ;
}
