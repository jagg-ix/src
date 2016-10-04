#include <stdio.h>
int main()
{
int nCongruencia,i,k=0;

FILE *input,*output;
int **matrix=NULL;

input=fopen("in.txt","rt");
output=fopen("out.txt","wt");
fscanf(input,"%d",&nCongruencia);

matrix=(int **) malloc( sizeof(int *) *nCongruencia);


for(i=0;  i< nCongruencia ;  i++ ){
	matrix[i]=(int *)malloc(sizeof(int) *20);	
}

for(i=0; i< nCongruencia ; i++){
	for(k=0;k< 20;k++){
		matrix[i][k]=k*nCongruencia + i ;
		fprintf(output," %d ",matrix[i][k]);
	}
	fprintf(output,"\n");
}

fclose(input);
fclose(output);
return 0;
}
