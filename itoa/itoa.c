#include <stdio.h>
#include <math.h>

int main()
{
	int numero=12345;
	int x=0;
	int i=0;
	char *strNumero=NULL;
	int z=0;
		
	z=numero;

	x=log10( numero);
	printf("log10(12345)=%d \n ",x);   
	strNumero=(char *)malloc(x+2);
	
	for(i=x; i>=0 ; i-- ){
		strNumero[x-i]= '0' + (numero /pow(10,i) );	
		numero= numero % (int )pow(10,i); 

	}
	
strNumero[x+2]=0x0;	
printf("int numero=%d \n",z);
printf("strNumero =%s\n",strNumero);
		
		

return 0;
}
