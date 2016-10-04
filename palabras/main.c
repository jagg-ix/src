#include <stdio.h>
#include <string.h>
 struct  diccionario{
                char *palabra;
                char letraRepetida;
                unsigned int veces;
        };

int main()
{

	FILE * input;
	int nlineas=0;
	int i=0;
	char cadena[255];
	int longW=0;
		
	

		
	struct diccionario *conjuntoW=NULL;
	
	
		
	int k=0;
	int conjuntoB[26]	;

	char letraMenor=0;
		
	input=fopen("in.txt","rt");
	
	fscanf(input, "%d",&nlineas);	
	
	conjuntoW= (struct diccionario *) malloc(sizeof(struct diccionario)*nlineas);
		
	for( i=0; i< nlineas; i++){
		fscanf(input, "%s",cadena);
		longW=strlen(cadena);
		
		conjuntoW[i].palabra=(char *)malloc(sizeof(char)*longW);
			
		strcpy(conjuntoW[i].palabra,cadena);
		setConjunto(conjuntoB, 26);

		for(k=0; k< longW; k++){
			conjuntoB[  conjuntoW[i].palabra[k] -'a'   ]++  ; 
			//sumo 1 al contador de la letra en conjuntoB 
			// contador de [a] es conjuntoB[0] 
		}
		conjuntoW[i].letraRepetida='a'+ mayor(conjuntoB,26) ;
		conjuntoW[i].veces=  conjuntoB[mayor(conjuntoB,26 )];	
		
		printf("palabra %s\n", conjuntoW[i].palabra);
		for( k=0; k< 26 ; k++){
			printf(" %d ", conjuntoB[k]);
		}
		printf("\n");
		printf("letra :  %c , %d \n",conjuntoW[i].letraRepetida, conjuntoW[i].veces) ;
	
	}

	ordenaBurbur( conjuntoW, nlineas ); 
	
	for( i=0; i< nlineas ; i++){
		printf("%s\n", conjuntoW[i].palabra );
	}
	
return 0;
}

void ordenaBurbur( struct diccionario *conjunto , int n ){
	int i=0;
	int k=0;
	
	struct diccionario *ptmp=NULL;
	
	for( ; ; ){
		for( ; ; ){
		}
	} 

	

return ;
}

void setConjunto( int *conjunto, int n){
	int i=0;
	for(i=0; i< n ; i++){
		conjunto[i]=0;
	}	
return ;
}


int mayor( int *conjunto, int n){
	int i=0;
	int esmayor=0;
	int k=0;
	
	esmayor= conjunto[0];
	for( k=0; k< n ; k++){	
			
		if( esmayor < conjunto[k] )
		{
			esmayor= conjunto[k];
			i=k;
		}
	
		
	}	
return i;
}
