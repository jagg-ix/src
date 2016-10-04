#include <stdio.h>
#include <stdlib.h>
typedef struct {
	short x;
	short y;
}point;



typedef struct gra{
	short x;
	short y;
	struct gra * sig;
} pline;




typedef struct absisas{
	short y1;
	short y2;
	struct absisas *sig;
}cabsi;
	

typedef struct gc{
	short x;
	cabsi cy;	
	pline  *linea;//puntos en x,y hasta y2 para cada "y" y "y2"
}gconvex;

#define INFINITO 0xffff
#define VERTICAL INFINITO

short m( point p2, point p1){
	if  ( p2.x == p1.x ){
		return	INFINITO; 
	}
	return (short ) ( ( p2.y- p1.y ) / ( p2.x - p1.x ) ) ;
	}

short   y( short m, short x, point p1){
		return (short)  (   (    m *( x - p1.x )     )  + p1.y   ) ;
	}


pline *  linea( point pp1, point pp2 ){ //p1 < p2
	int x=0;
	point p;
	
	point p1 , p2 ;	
	pline *retlinea=NULL;

	int inclinacion=0;
	
	if( pp1.x< pp2.x ){
	 p1= pp1;
	 p2= pp2;
	}else
	if( pp1.x > pp2.x ){
	p1 = pp2 ;
	p2 = pp1 ;
	}

	if( p2.x == p1.x ){ //linea vertical
		printf(" p2.x= p1.x x=%d \n", p1.x);
		p.x = p1.x;
		for(p.y= p1.y+1 ;   ( p.y < p2.y) ; p.y++){
			inserta( p, &retlinea );
		}
		return  ( retlinea );
	}
	else
		inclinacion=m(p2, p1 );
		if ( inclinacion ==0 ){ //linea horizontal
			printf("inclinacion es igual a 0 \n");
			p.y= p1.y ;
			for( p.x = p1.x+1  ; p.x < p2.x ; p.x++ ){
				inserta( p, &retlinea );
			}
			return ( retlinea );	
		}//linea es recta horizontal
		else{ /* inclinacion no es vertical ni horizontal */
			printf("P1(%d,%d)  P2(%d,%d)\n", p1.x, p1.y, p2.x, p2.y );

			for( p.x= p1.x +1;  p.x < p2.x ; p.x++   ){
				 p.y= y(   inclinacion ,  p.x  ,  p1   );
				 inserta( p, &retlinea );
			}
			return ( retlinea );

		}
	

	return ( retlinea );	
	
}


pline * inserta( pline nuevo, pline ** conjunto ){
  pline **con=conjunto;      
  pline *p;

  if( *con ==NULL ) {

   *con=( pline * ) malloc( sizeof(pline) ) ;
    (*con)->x = nuevo.x;
    (*con)->y = nuevo.y;
    (*con)->sig = NULL;
    return  *con;
  }else{
		p=*con;
  		while( p->sig ){ //mientras el siguiente no sea null
    			p=p->sig ;     //pasarce al siguiente
  		}
  
  	p->sig=(pline * ) malloc( sizeof( pline) ) ;
  	p= p->sig;	
  	p->x = nuevo.x ;
  	p->y = nuevo.y ; 
  	p->sig = NULL;
	
	}
  return p;
}



pline * buscar( pline pbuscado, pline * conjunto ){
  pline *p=conjunto;


  while( p ){  //cuando p es null termina;
    if(  (  p->x == pbuscado.x  ) && ( p->y== pbuscado.y ) ) {
      return p;
    }
    p=p->sig;
  }
  
  return p ;
}



pline * buscarYs( pline pbuscado, pline * conjunto ){
  pline *p=conjunto;

  while( p ){
        if(    ( p->x ==pbuscado.x ) && ( p->y > pbuscado.y ) ) {
	  return  p;
	}
	p= p->sig ;
  }

  return p;
}


/*
Funcion principal,recive 
*/
short    contarBorregosSeguros(  pline *conOvejas, pline *conEsquinas ){
  
  pline  *conO=  conOvejas ;
  pline  *conE=  conEsquinas;
  pline  *conP = NULL; 
  pline  *conPuntos=NULL; //aqui estan todos los puntos
  pline  *p;
  point  p1, p2 ;
  
  short borregosSalvo=0;

while( conE   ){ //todas las esqinas
  
  if( conP==NULL) {
    conP= (pline * ) malloc( sizeof( pline) ) ;    
    conP->sig=NULL;
    conPuntos=conP ;
  }else
    {
      conP->sig=( pline * )  malloc( sizeof( pline ) ) ;
    }
    conP->x = conE->x;
    conP->y = conE->y;
    
    p1.x =conE->x;
    p1.y =conE->y;
    
    p2.x =conE->x;
    p2.y =conE->y;

    conP->sig  =   linea(  p1 , p2  )         ; 
    p= conP->sig;

    while(  p->sig ) //hasta el ultimo punto de la linea, antes de p2
      {
	p=p->sig;
      }
    p->sig=(pline * ) malloc( sizeof( pline) ) ;
    p=p->sig;
    p->x= conE->sig->x;  
    p->y= conE->sig->y;  //agregar el  extremo p2
    
    p->sig= NULL;
    
    conP=p;
    

    conE= conE->sig; //avanza siguiente esquina;
}
  
/* conPuntos = conjunto de todos los puntos  */


 p=conPuntos;

 while ( p ){
   printf( " %d,%d \n" , p->x, p->y ) ;
   p=p->sig;
 }




  
  
  return  ( borregosSalvo  )  ;  

  
}


 void imprimirC(pline *con ){
	pline *p=con;
	while( p ){
	  printf("(%d,%d)  ",p->x, p->y) ;
		p=p->sig;
	}
	return ;
}

long cuentaConjunto( pline *con ){
	long numero=0;
	pline *p=con;
	while( p ){
		numero++;
		p=p->sig;
	}	
return numero ;
}


int main()
{
  
  FILE *input;
  
  int  nOvejas=10;

  int  nEsquinas=0;
  
  short i=0;
  
 pline *ovejas=NULL;
  pline *esquinas=NULL;
  
  pline punto;
  pline * conjuntoG=NULL ;
  pline * conjuntoO=NULL;

  pline *p=NULL;
  point p1, p2 ;

   if (  !(input=fopen("bahaa.in" , "r+t")  ) ) {
		perror( " no puedo abrir el archivo \n") ;     	
	}
    
  fscanf( input, "%d %d", &nOvejas, &nEsquinas );

	printf("se leeran %d ovejas \n", nOvejas );
    	printf("se leeran %d esquinas \n", nEsquinas );

	   printf("ovejas \n"); 
 	   for( i=0; i< nOvejas ; i++ ) {
      		fscanf( input, "%d" , &punto.x  ) ;
      		fscanf( input, "%d" , &punto.y  ) ;
    		inserta(punto, &conjuntoO );
		printf("(%d,%d) \n", punto.x , punto.y );	
    		}  
	   printf("esquinas \n");
   	for( i=0 ; i< nEsquinas; i++ ){	
		fscanf( input, "%d", &punto.x ) ;	
		fscanf( input, "%d", &punto.y ) ;
		inserta( punto, &esquinas );
		printf("(%d,%d) \n",punto.x , punto.y);
	}

	p=conjuntoO;

	printf("conjunto de puntos de Ovejas \n");
	while (  p ){
		printf(" (%d,%d) \n", p->x, p->y );
		p=p->sig;
	}    
 
	printf("conjunto de punto de Esquinas \n");
	p=esquinas;
	while( p ){
		printf(" (%d,%d) \n", p->x, p->y );
		p=p->sig;
	}

	p=esquinas ;
	
	p1.x = p->x;
	p1.y = p->y;
	
	p2.x = p->sig->x;
	p2.y = p->sig->y;

	conjuntoG=linea( p1, p2 );	
	printf(" puntos entre el primer y segundo punto \n");
	printf(" p1.x = %d, p1.y= %d | p2.x=%d,p2.y=%d \n ", p1.x, p1.y, p2.x , p2.y);

	printf(" %p direcccion que apunta conjuntoG \n", conjuntoG );
	p=conjuntoG;


	while( p ) {
		printf("(%d,%d)\n", p->x, p->y ); 
	p=p->sig;
	}	
  return 0 ; 
}


