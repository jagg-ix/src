#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char **argv)
{
  FILE *fichero ;
  int c;
  char *linea[10];
  char  mensaje[80];
  fichero=fopen( argv[1], "r+");
 
  
  
      fgets(mensaje,80  , fichero );
      printf("la linea leida es \n %s" , mensaje );
      fclose(fichero );
      return  0 ;

}
