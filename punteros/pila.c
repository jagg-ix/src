#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodop{
	char *dato ;
	struct nodop *siguiente ;
	struct nodop *anterior ;
	}nodo ;
	
	typedef nodo   pila ;
	typedef nodo * pPila  ;
	typedef pila   BP;
	typedef pila   SP;
	
int main(){
	pila *stack ;
	stack =	NULL;
	
	char ecuacion = " x = 5 + 8 * 2 " ; // el resultado es igual a 5 + 16 = 21 
	
	
	return 0 ;
}

char * put(pstack_BP ,char *mensaje ){
		pPila nuevoElemento ;
		pPila actual ;
		SP stack_SP ;
		actual=stack_BP ;
		
		if(actual!=NULL ){
			//hay algo en la pila , se introduce el valor en la ultima posicion
			actual=ultimapos( stack_BP) ;
			actual->siguiente=( pPila ) malloc( sizeof(pila) );
			actual->siguiente->anterior = actual ;
			actual=actual->siguiente ;
			actual->siguiente = NULL ;
			actual->dato=(char *) malloc( strlen(mensaje ) * sizeof(char) ) ;
			
			}else{
				// no hay nada en la pila ; se introduce algo por primera vez
			actual->siguiente=( pPila ) malloc( sizeof(pila) );
			actual->siguiente->anterior = actual ;
			actual=actual->siguiente ;
			actual->siguiente = NULL ;
			actual->dato=(char *) malloc( strlen(mensaje ) * sizeof(char) ) ;
			
				}
		 
		
			stack_SP = actual ;
		
	return stack_SP->dato ;}

char * pop( BP stack_BP ){
	pPila actual ;
	char * msj ;
	actual = stack_BP ;
		if ( actual != NULL ){
			actual = ultimapos( stack_BP );
			actual->anterior->siguiente=NULL ;
			msj  = (char * ) malloc( strlen(actual->dato) * sizeof( char ) ) ;
			actual->anterior->siguiente=NULL ;
		}else{
			return NULL ;
			}
	}
	
	pPila ultimapos( BP stack_BP ){
			pPila actual ;
		actual = stack_BP ;
			if(actual != NULL )
				ultimapos( actual->siguiente ) ;
			else
				return actual ;
		}