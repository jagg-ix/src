#include <stdio.h>
int main(){


typedef 	union _reg32 {
			unsigned int       eax ;
			union _reg16 {
				unsigned short  ax ;
				struct _reg8 {
					unsigned char al ;
					unsigned char ah ;
				} reg8;	
				
			} reg16 ; 
		
		} reg_t   ; 

	reg_t _reg;
	
	   _reg.eax = scanreg();
	printf("%d bits  o %d bytes \n" ,  sizeof( double )* 8 , sizeof( double) );
	printf("------>Contenido de EAX :  %x con un tamaño de %d bits  |  %d bytes \n ", _reg.eax  , sizeof(unsigned int)*8 , sizeof(unsigned int) );
	printf("------>Contenido de AX :  %x  con un tamaño de %d bits  |  %d bytes \n ", _reg.reg16.ax , sizeof(short)*8  , sizeof(short  )        );
	printf("------>Contenido de Ah :  %x  con un tamaño de %d bits  |  %d bytes \n ",  _reg.reg16.reg8.ah , sizeof(unsigned char) *8 , sizeof(unsigned char ) );
	printf("------>Contenido de Al:  %x \n ", _reg.reg16.reg8.al  );
	return 0 ;
}	
