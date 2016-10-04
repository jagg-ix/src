#include <stdio.h>
#include <stdlib.h>

int mcd( int n, int v);

int main()
{
int total=0;
int n,m;
int i=0;

FILE *input;
input=fopen("in.txt", "rt");

fscanf(input,"%d",&total);
for(i=0; i< total; i++){
	fscanf(input,"%d %d",&n,&m);
	printf("El maximo mcd(%d,%d)=%d\n",n,m,mcd(n,m));
}


fclose(input);

return 0 ;
}


/*
int mcd( int u, int v)
{
int t=0;
while( u> 0 ){
	if( u<v ){ t=v; v=u; u=v ;}
	u=   u -v  ; 
}
return v;
}

*/



int mcd(int u,int v){
	int t=0;
	while( u>0 )
	{
		printf("t=%d, u=%d, v=%d\n",t,u,v);
		if(u < v ){ t=u; u=v ; v=t ;
		printf("cambio t=%d, u=%d, v=%d\n",t,u,v);
		}
		u=u-v;	
	}
		printf("t=%d, u=%d, v=%d\n",t,u,v);
return v;
}


