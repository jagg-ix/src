#include <stdio.h>
	
	unsigned int   _add ( int  , int );


	
	int main() {

		unsigned  int   suma=0x0 ;
		 suma =	_add(0xffff0000 , 0x0000fff0); // el valor que pasa  es el valor que  regresa 
		 	 /*
			  * seria lo mismo que una funcion
			  * add( int i )  {
			  * 
			  * return i ;
			  * }
			  */
		 printf(" el resultado es :  %x \n ", suma );

		
		
		
	return 0 ;
	}
	

	
