#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strChar(char *mensaje , char *c) ;
int main()
{
	int a, *ptr_a ;
	char c , *ptr_c ;
	char **ptr_ptr_c ;
	char palabra[100];
	char *ptr_palabra;
    char *(*funcion)( char * ,char *) ;
	char *vector ;
	strcpy(palabra+18,"malas palabras son malos pensamientos hijo");
    ptr_c =palabra + 18 ;
    funcion=strChar;
	
	funcion(palabra, ptr_c);
	ptr_ptr_c = & ptr_c ;
	
	*ptr_ptr_c += 6 ;
	 
printf("%s",ptr_c);
	
	
	
return 0 ;
}

char *strChar( char *mensaje , char *c ){
		
	printf(" \n el mensaje es %s \n",c);

	return c ;
	}

	

