#include <stdio.h>


int main()
{

FILE *input;

int n=0;
int m=0;
int *s=NULL;
unsigned int i=0,j=0,k=0,z=0;
struct triple{
	int m1;
	int m2;
	int m3;
	};

struct triple* conjunto;
input=fopen("in.txt", "rt");


fscanf(input,"%d",&n);
fscanf(input,"%d",&m);
printf("N=%d",n);
s=(int *) malloc( sizeof(int) * m) ; 

for( ;i < m-1 ; i++){
	 fscanf(input,"%d",&s[i]);
}

conjunto=( struct triple *) malloc( sizeof(struct triple) *(m*m*m) );

for(i=0; i< m ;i++){

	for(k=0; k<m-1; k++){
		for(j=0; j<m-1; j++){
			if(j==k){
				continue;
			}
			for(z=0; z<m-1; z++){
				if(z==j){
					continue;
				}
				 if(s[k]==s[j] || s[k]==s[z] || s[j]==s[z] )
				{
					continue;	
				}
				if(!j>z ){
					continue;
				}
				conjunto[i].m1=s[k];
				conjunto[i].m2=s[j];
				conjunto[i].m3=s[z];	
			
				printf("S[%d]=<%d,%d,%d> \n",i,  conjunto[i].m1   ,  conjunto[i].m2    ,conjunto[i].m3   );
	
				
			}
			printf("\n");
		}
	}
}

for(i=0; i< (m*m*m);i++ ){
	printf("<%d,%d,%d> \n",  conjunto[i].m1   ,  conjunto[i].m2    ,conjunto[i].m3   );
}


return 0;
}










