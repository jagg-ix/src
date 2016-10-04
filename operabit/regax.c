#include <stdio.h>

typedef union  {
	double eax ;
		union  {
			unsigned int ax ;
			struct {
				unsigned char ah;
				unsigned char al;
			} _ax ;
		} ax ;
	} _reg ;


int main (){
	_reg   task; // defino una tarea con los registros

	task.eax = 0xffffffff ;

	printf( "valor de eax = %X \n", task.eax );
	printf( "valor de ax = %X \n" , task.ax );
	printf( "valor de ah = %X \n" , task.ax._ax.ah);
	printf( "valor de al = %X \n" , task.ax._ax.al);

return ;
}

	
