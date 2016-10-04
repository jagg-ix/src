#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
	char * dato ;
	struct p *next ;
	struct  p *ant ;
	} nodo ;
	
	
	typedef nodo  lista ;
	typedef nodo  *plista ;

	int main(){
	plista  stack ;
	plista  bp ;
		stack=NULL ;
		bp = stack ;
		
		intro( &stack , "Hola" );
		
		printf( "%s" , stack->dato);
		
		
		return 0 ;
		}
		
		
		void intro( plista  *stack , char *msg ){
		 
			plista nuevo ;
		    nuevo =( plista) malloc( sizeof(lista) ) ;
			nuevo->dato = (char * ) malloc( 12 );
			strcpy ( nuevo->dato,msg );
			*stack =nuevo ;
			return ;
			}
	
	