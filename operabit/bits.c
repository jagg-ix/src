#include <stdio.h>
int main(){
	unsigned char operando=1;
	unsigned char memory[]={ "\x01","\x02","\x03", "\x04","\x05","\x06" } ;
	unsigned char i=1;
 	for(; i<6 ;i++)
	{	
		operando <<= i;
		printf("valor actual %x , cuando rota %x  veces \n ",operando , i);
		
	}
	return 0;
}	
	
