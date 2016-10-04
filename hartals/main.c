#include <stdio.h>
enum  {domingo,lunes,martes,miercoles,jueves,vienes,sabado};

int main()
{
int t=0;
int dias=0;
unsigned  int *h=NULL; // n por cada partido politico donde n= numero de dias /fiesta y fiesta 

unsigned int **S=NULL; // 

unsigned  int p=0;
unsigned int i=0;
unsigned int k=0;
unsigned int *C=NULL;
unsigned int z=0;
FILE *input;



input=fopen("in.txt", "rt");
fscanf(input,"%d",&t);  //numero de casos 


for( z=0 ; z < t ; z++ ){  //  procesar cada caso 

	fscanf(input,"%d",&dias); //dias a simular por caso
	fscanf(input,"%d",&p);    //partidos politicos en el caso 
	h=( unsigned int * ) malloc( sizeof( int ) *p );
	
	//introducir periodo de cada partido

 
	for( i=0 ; i< p ; i++){ //meter cada lapso de hartal  por partido
		fscanf( input, "%d", &h[i]); // un h[i] por cada p
		//printf(" h[%d]=%d\n",i,h[i]);

	}


	
	/* Crearemos un conjunto por cada h[i]  partido politico */
	//Inicializamos S 
	S=(unsigned int ** ) malloc(sizeof(unsigned int *) * p);
		for( i=0; i< p  ; i++ ){
			S[i]=(unsigned int * ) malloc(sizeof( unsigned int) *dias );
		}//le asigno memoria a cada conjunto 
	
	


	//Inicializamos cada entrada
	
	for( i=0; i< p ; i++){
		for(k=0; k< dias; k++){
			S[i][k]=0;
		}
	}



	// lleno cada conjunto con su serie  
	for( i=0 ; i< p ; i++ ){
		k=0;	
		for(k+=h[i] ; k<=dias ; k+=h[i] ){
				
				if (  !diaperdido( k-1)   ){
				 	 S[i][k]=1 ;
					 //printf(" [%d][%d]=1",i,k);
				}
					//printf(" [%d][%d]=0",i,k);  
				
		}	
		//printf("\n");	
	}


	C=(int *)malloc( sizeof(int ) * dias);

	for(i=0; i< dias; i++){
		C[i]=0;
	}

	for(i=0 ;i< p;i++ ){ // union de C con cada Serie de cada P partido
		conjunto_union( S[i], C, C, dias );
	}	
	
	printf("%d\n",cuentaElementos( C, dias )  ); 				
	
}




return 0;
}




void  conjunto_union( int *A, int *B,int *C,int n){
	
	int i=0;
	for( i=0; i< n ; i++){
		C[i]= A[i] | B[i] ;
	}
	//C es la union de A , B
return ;
}


unsigned int cuentaElementos( int *C,int n ) {
	int i=0;
	unsigned int sizeC=0;
	
	for( i=0; i< n ; i++){
		if(C[i]==1  ){
			sizeC++;	
		}
	}	
return  sizeC;
}
  
unsigned int dia( unsigned int i){
	return (i%7 ) ;
}

unsigned int diaperdido( unsigned int d){
	if(  dia(d)==6 || dia(d)==5)
		return 1;
	else
		return 0;
}
