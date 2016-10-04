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
printf("N=%d\n",n);
s=(int *) malloc( sizeof(int) * m) ; 
printf("S={" );
for( ;i < m-1 ; i++){
	 fscanf(input,"%d",&s[i]);
	 printf(" %d",s[i]);
}
printf("}\n");

conjunto=( struct triple *) malloc( sizeof(struct triple) *(m*m*m) );
i=0;

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
			 	
				if(z>j){
					continue;
				}
				if(j>k){
					continue;
				}
				conjunto[i].m1=s[k];
				conjunto[i].m2=s[j];
				conjunto[i].m3=s[z];
				if(  (s[k]+s[j]+s[z])==n){
					printf("La relacion +() del triple  <%d,%d,%d>==%d\n",s[k],s[j],s[z],n);
					return ;
 
				}	
				//printf("S[%d]=<%d,%d,%d> \n",i,  conjunto[i].m1   ,  conjunto[i].m2    ,conjunto[i].m3   );
				i++;
				
			}
		}
	}

for(i=0; i< m-1;i++ ){
	printf("<%d,%d,%d> \n",  conjunto[i].m1   ,  conjunto[i].m2    ,conjunto[i].m3   );
}


return 0;
}










