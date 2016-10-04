#include <stdio.h>

int main( int argv, char **args )
	{
	char *mensaje=*(args+1);
	printf(" %s  \n", mensaje );
	return 0;
	}	
