#include <stdio.h>
#include <stdlib.h>

:qtypedef struct p{
	signed char x;
	unsigned char y;
}punto ;    

typedef punto **linea;

typedef struct graf{
	punto  pnodo;
	punto *sig;
	} grafica;
	
short m( punto p1, punto p2 )
{
  return (     (p2.y - p1.y ) - ( p2.x - p1.x )  ) ;
}



short y(  punto p1 , short x ,short  m )
{ 
 
  return   (   ( m * ( x - p1.x ) )  + p1.y  )   ;
}


typedef struct yl{
   short y1;
   signed y2;
 
   struct yl *  ysig;

} ylist;

typedef struct {
  short x;
  ylist yl;
}nodo;


punto * agregaPunto( punto p , grafica  * g  )
	{	punto *pn=g->pnodo;
		while(  pn->sig ){
			pn=pn->sig;
		}
		pn->x= p.x;	
		pn->y= p.y;
		pn->sig=NULL;
		
	return pn ;
}


punto * buscaPunto( punto p , grafica * g )
	{
		punto *pn=g->pnodo;
		
		while(  pn->sig ){
			if(  (  pn->x == p.x )   && ( pn->y == p.y  )  )
				{
					break  ;
				}
		}	
	return pn;
	}

unsigned long contarPuntos( grafica *g )
	{
		punto *pn=g->pnodo;
		long contador=1;
		while ( pn->sig )
		{
			contador++;
			pn=pn->sig;
		
 		}
	return contador;
	}

punto *vinternoAlto( grafica  *g )
	{
		punto *pn=g;
		punto  ptmp=*pn;
		while( pn->sig ){
				 	
		}	
	return pn ;
	}
int main(){
		
	
 	return 0 ;
}
